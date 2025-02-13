#include <cstdlib>
#include <list>
#include "jvmti.h"
#include <string>
#include <cstdint>

//extern "C" {

static jclass ClassAssertionError;
static jclass ClassClass;
static jclass ClassThread;
static jclass ClassIllegalArgumentException;
static jclass ClassNoSuchElementException;
static jclass ClassNativeException;
static jclass ClassClassFormatError;
static jclass ClassClassCircularityError;
static jclass ClassClassDefinition;
static jclass ClassClassLoadHook;
static jclass ClassBoxedValue;
static jclass ClassBoolean;
static jclass ClassByte;
static jclass ClassCharacter;
static jclass ClassDouble;
static jclass ClassFloat;
static jclass ClassInteger;
static jclass ClassLong;
static jclass ClassShort;
static jmethodID ClassClassLoadHook_transform;
static jmethodID ClassBoolean_booleanValue;
static jmethodID ClassByte_byteValue;
static jmethodID ClassCharacter_charValue;
static jmethodID ClassDouble_doubleValue;
static jmethodID ClassFloat_floatValue;
static jmethodID ClassInteger_intValue;
static jmethodID ClassLong_longValue;
static jmethodID ClassShort_shortValue;
static jfieldID ClassClassDefinition_clazz;
static jfieldID ClassClassDefinition_bytes;
static jfieldID ClassBoxedValue_value;
static JavaVM * javaVM;
static jvmtiEnv * jvmti;

static bool hasRegClHook = false;

static JavaVM * GetVM(JNIEnv *env) {
    if (javaVM != nullptr) return javaVM;
    JavaVM *jvm;
    env->GetJavaVM(&jvm);
    return jvm;
}

static jvmtiEnv * GetJvmti(JavaVM *jvm) {
    if (jvmti != nullptr) return jvmti;
    void *ptr;
    jvm->GetEnv(&ptr, JVMTI_VERSION_1_2);
    return (jvmtiEnv *) ptr;
}

static std::list<jobject> classLoadHooks; // NOLINT(cert-err58-cpp)

static jthread GetCurrentThread(JNIEnv *env) {
    jmethodID mid = env->GetStaticMethodID(ClassThread, "currentThread", "()Ljava/lang/Thread;");
    return env->CallStaticObjectMethod(ClassThread, mid);
}

static bool EnsureStackDoesNotContain(jvmtiEnv *jvmTi, JNIEnv *env, jmethodID mid) {
    jvmtiFrameInfo frames[300];
    jint count;
    jvmTi->GetStackTrace(GetCurrentThread(env), 0, 300, frames, &count);
    for (int i = 0; i < count; ++i) {
        if (frames[i].method == mid) return false;
    }
    return true;
}

static void classLoadHook(jvmtiEnv *jvmti_env,
                          JNIEnv* jni_env,
                          jclass class_being_redefined,
                          jobject loader,
                          const char* name,
                          jobject protection_domain,
                          jint class_data_len,
                          const unsigned char* class_data,
                          jint* new_class_data_len,
                          unsigned char** new_class_data) {
    if (name == nullptr) return;
    jbyteArray arr = jni_env->NewByteArray(class_data_len);
    jni_env->SetByteArrayRegion(arr, 0, class_data_len, (jbyte*) class_data);
    jstring j_name = jni_env->NewStringUTF(name);
    for (const jobject &item : classLoadHooks) {
        jmethodID mid2 = jni_env->GetMethodID(jni_env->GetObjectClass(item), "transform", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B");
        if (EnsureStackDoesNotContain(jvmti_env, jni_env, mid2)) {
            jobject obj = jni_env->CallObjectMethod(item, ClassClassLoadHook_transform, loader, j_name, class_being_redefined, protection_domain, arr);
            if (obj != nullptr) {
                arr = reinterpret_cast<jbyteArray>(obj);
            }
        }
    }
    *new_class_data_len = jni_env->GetArrayLength(arr);
    if (jvmti_env->Allocate(*new_class_data_len, new_class_data) != 0) {
        return;
    }
    jni_env->GetByteArrayRegion(arr, 0, *new_class_data_len, (jbyte*) *new_class_data);
}

static void InitCapabilities(JavaVM *vm) {
    jvmtiCapabilities capabilities;
    jvmtiEnv * jvmTi = GetJvmti(vm);
    jvmTi->GetCapabilities(&capabilities);
    capabilities.can_generate_all_class_hook_events = 1;
    capabilities.can_retransform_classes = 1;
    capabilities.can_retransform_any_class = 1;
    capabilities.can_redefine_classes = 1;
    capabilities.can_redefine_any_class = 1;
    jvmTi->AddCapabilities(&capabilities);
    jvmTi->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_CLASS_FILE_LOAD_HOOK, nullptr);
    if (hasRegClHook) return;
    jvmtiEventCallbacks callbacks;
    callbacks.ClassFileLoadHook = classLoadHook;
    jvmTi->SetEventCallbacks(&callbacks, sizeof(callbacks));
    hasRegClHook = true;
}

static void InitTools(JNIEnv *env) {
    javaVM = GetVM(env);
    jvmti = GetJvmti(javaVM);
    classLoadHooks = std::list<jobject>();
    ClassAssertionError = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/AssertionError")));
    ClassClass = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Class")));
    ClassThread = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Thread")));
    ClassIllegalArgumentException = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/IllegalArgumentException")));
    ClassNoSuchElementException = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/util/NoSuchElementException")));
    ClassNativeException = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("net/blueberrymc/nativeutil/NativeException")));
    ClassClassFormatError = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/ClassFormatError")));
    ClassClassCircularityError = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/ClassCircularityError")));
    ClassClassDefinition = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("net/blueberrymc/nativeutil/ClassDefinition")));
    ClassClassLoadHook = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("net/blueberrymc/nativeutil/ClassLoadHook")));
    ClassBoxedValue = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("net/blueberrymc/nativeutil/BoxedValue")));
    ClassBoolean = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Boolean")));
    ClassByte = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Byte")));
    ClassCharacter = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Character")));
    ClassDouble = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Double")));
    ClassFloat = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Float")));
    ClassInteger = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Integer")));
    ClassLong = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Long")));
    ClassShort = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Short")));
    ClassClassLoadHook_transform = env->GetMethodID(ClassClassLoadHook, "transform", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B");
    ClassBoolean_booleanValue = env->GetMethodID(ClassBoolean, "booleanValue", "()Z");
    ClassByte_byteValue = env->GetMethodID(ClassByte, "byteValue", "()B");
    ClassCharacter_charValue = env->GetMethodID(ClassCharacter, "charValue", "()C");
    ClassDouble_doubleValue = env->GetMethodID(ClassDouble, "doubleValue", "()D");
    ClassFloat_floatValue = env->GetMethodID(ClassFloat, "floatValue", "()F");
    ClassInteger_intValue = env->GetMethodID(ClassInteger, "intValue", "()I");
    ClassLong_longValue = env->GetMethodID(ClassLong, "longValue", "()J");
    ClassShort_shortValue = env->GetMethodID(ClassShort, "shortValue", "()S");
    ClassClassDefinition_clazz = env->GetFieldID(ClassClassDefinition, "clazz", "Ljava/lang/Class;");
    ClassClassDefinition_bytes = env->GetFieldID(ClassClassDefinition, "bytes", "[B");
    ClassBoxedValue_value = env->GetFieldID(ClassBoxedValue, "value", "Ljava/lang/Object;");
    InitCapabilities(javaVM);
}

static void AddClassLoadHook(JNIEnv *env, jobject handler) {
    if (!env->IsInstanceOf(handler, ClassClassLoadHook)) {
        env->ThrowNew(ClassIllegalArgumentException, "handler must implement net.blueberrymc.nativeutil.ClassLoadHook");
        return;
    }
    jobject globalHandler = env->NewGlobalRef(handler);
    classLoadHooks.push_back(globalHandler);
}

static jclass GetDeclaringClass(JNIEnv *env, jobject obj) {
    jmethodID mid_getDeclClass = env->GetMethodID(env->GetObjectClass(obj), "getDeclaringClass", "()Ljava/lang/Class;");
    if (mid_getDeclClass == nullptr) {
        env->ThrowNew(ClassAssertionError, "Could not find method ???.getDeclaringClass()Ljava/lang/Class;");
        return nullptr;
    }
    return reinterpret_cast<jclass>(env->CallObjectMethod(obj, mid_getDeclClass));
}

static void ThrowClass(JNIEnv *env, jclass clazz) {
    jmethodID mid = env->GetMethodID(clazz, "<init>", "()V");
    env->Throw(reinterpret_cast<jthrowable>(env->NewObject(clazz, mid)));
}

static jboolean ToBoolean(JNIEnv *env, jobject obj) {
    return env->CallBooleanMethod(obj, ClassBoolean_booleanValue);
}

static jbyte ToByte(JNIEnv *env, jobject obj) {
    return env->CallByteMethod(obj, ClassByte_byteValue);
}

static jchar ToChar(JNIEnv *env, jobject obj) {
    return env->CallCharMethod(obj, ClassCharacter_charValue);
}

static jdouble ToDouble(JNIEnv *env, jobject obj) {
    return env->CallDoubleMethod(obj, ClassDouble_doubleValue);
}

static jfloat ToFloat(JNIEnv *env, jobject obj) {
    return env->CallFloatMethod(obj, ClassFloat_floatValue);
}

static jint ToInt(JNIEnv *env, jobject obj) {
    return env->CallIntMethod(obj, ClassInteger_intValue);
}

static jlong ToLong(JNIEnv *env, jobject obj) {
    return env->CallLongMethod(obj, ClassLong_longValue);
}

static jshort ToShort(JNIEnv *env, jobject obj) {
    return env->CallShortMethod(obj, ClassShort_shortValue);
}

static jvalue * TransformParams(JNIEnv *env, jobjectArray params) {
    auto length = env->GetArrayLength(params);
    auto *object_args = static_cast<jvalue *>(malloc(length * sizeof(jvalue)));
    for (int i = 0; i < length; ++i) {
        jobject obj = env->GetObjectArrayElement(params, i);
        if (env->IsInstanceOf(obj, ClassBoolean)) {
            object_args[i].z = ToBoolean(env, obj);
        } else if (env->IsInstanceOf(obj, ClassByte)) {
            object_args[i].b = ToByte(env, obj);
        } else if (env->IsInstanceOf(obj, ClassCharacter)) {
            object_args[i].c = ToChar(env, obj);
        } else if (env->IsInstanceOf(obj, ClassDouble)) {
            object_args[i].d = ToDouble(env, obj);
        } else if (env->IsInstanceOf(obj, ClassFloat)) {
            object_args[i].f = ToFloat(env, obj);
        } else if (env->IsInstanceOf(obj, ClassInteger)) {
            object_args[i].i = ToInt(env, obj);
        } else if (env->IsInstanceOf(obj, ClassLong)) {
            object_args[i].j = ToLong(env, obj);
        } else if (env->IsInstanceOf(obj, ClassShort)) {
            object_args[i].s = ToShort(env, obj);
        } else if (env->IsInstanceOf(obj, ClassBoxedValue)) {
            object_args[i].l = env->GetObjectField(obj, ClassBoxedValue_value);
        } else {
            object_args[i].l = obj;
        }
    }
    return object_args;
}


static std::string concat(const char * chars, int i) {
    return std::string(chars) + std::to_string(i);
}

static inline void* addr_from_java(jlong addr) {
    // This assert fails in a variety of ways on 32-bit systems.
    // It is impossible to predict whether native code that converts
    // pointers to longs will sign-extend or zero-extend the addresses.
    //assert(addr == (uintptr_t)addr, "must not be odd high bits");
    return (void*)(uintptr_t)addr;
}

static inline jlong addr_to_java(void* p) {
    //assert(p == (void*)(uintptr_t)p, "must not be odd high bits");
    return (uintptr_t)p; // NOLINT(cppcoreguidelines-narrowing-conversions)
}

//}
