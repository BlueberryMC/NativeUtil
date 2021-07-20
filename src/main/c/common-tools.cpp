#include <cstdlib>
#include <list>
#include "jvmti.h"
#include <iostream>

extern "C" {

static jclass ClassAssertionError;
static jclass ClassClass;
static jclass ClassMethod;
static jclass ClassIllegalArgumentException;
static jclass ClassNoSuchElementException;
static jclass ClassBoolean;
static jclass ClassByte;
static jclass ClassCharacter;
static jclass ClassDouble;
static jclass ClassFloat;
static jclass ClassInteger;
static jclass ClassLong;
static jclass ClassShort;
static jclass ClassClassLoadHook;

static JavaVM * GetVM(JNIEnv *env) {
    JavaVM *jvm;
    env->GetJavaVM(&jvm);
    return jvm;
}

static jvmtiEnv * GetJvmti(JavaVM *jvm) {
    void *ptr;
    jvm->GetEnv(&ptr, JVMTI_VERSION_1_1);
    return (jvmtiEnv *) ptr;
}

static std::list<jobject> classLoadHooks; // NOLINT(cert-err58-cpp)

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
    jmethodID mid = jni_env->GetMethodID(ClassClassLoadHook, "transform", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B");
    jbyteArray arr = jni_env->NewByteArray(class_data_len);
    jni_env->SetByteArrayRegion(arr, 0, class_data_len, (jbyte*) class_data);
    jstring j_name = jni_env->NewStringUTF(name);
    for (const jobject &item : classLoadHooks) {
        jobject obj = jni_env->CallObjectMethod(item, mid, loader, j_name, class_being_redefined, protection_domain, arr);
        if (obj != nullptr) {
            arr = reinterpret_cast<jbyteArray>(obj);
        }
    }
    *new_class_data_len = jni_env->GetArrayLength(arr);
    jvmti_env->Allocate(*new_class_data_len, new_class_data);
    jni_env->GetByteArrayRegion(arr, 0, *new_class_data_len, (jbyte*) *new_class_data);
}

static void InitTools(JNIEnv *env) {
    classLoadHooks = std::list<jobject>();
    ClassAssertionError = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/AssertionError")));
    ClassClass = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Class")));
    ClassMethod = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/reflect/Method")));
    ClassIllegalArgumentException = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/IllegalArgumentException")));
    ClassNoSuchElementException = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/util/NoSuchElementException")));
    ClassBoolean = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Boolean")));
    ClassByte = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Byte")));
    ClassCharacter = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Character")));
    ClassDouble = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Double")));
    ClassFloat = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Float")));
    ClassInteger = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Integer")));
    ClassLong = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Long")));
    ClassShort = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/Short")));
    ClassClassLoadHook = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("net/blueberrymc/native_util/ClassLoadHook")));
    jvmtiCapabilities capabilities;
    jvmtiEnv * jvmti = GetJvmti(GetVM(env));
    jvmti->GetCapabilities(&capabilities);
    capabilities.can_generate_all_class_hook_events = 1;
    capabilities.can_retransform_classes = 1;
    capabilities.can_retransform_any_class = 1;
    jvmti->AddCapabilities(&capabilities);
    jvmtiEventCallbacks callbacks;
    callbacks.ClassFileLoadHook = classLoadHook;
    jvmti->SetEventCallbacks(&callbacks, sizeof(callbacks));
    jvmti->SetEventNotificationMode(JVMTI_ENABLE, JVMTI_EVENT_CLASS_FILE_LOAD_HOOK, nullptr);
}

static void AddClassLoadHook(JNIEnv *env, jobject handler) {
    if (!env->IsInstanceOf(handler, ClassClassLoadHook)) {
        env->ThrowNew(ClassIllegalArgumentException, "handler must implement net.blueberrymc.native_util.ClassLoadHook");
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

static jobjectArray GetMethodParams(JNIEnv *env, jobject m) {
    jmethodID mid_ptypes = env->GetMethodID(ClassMethod, "getParameterTypes", "()[Ljava/lang/Class;");
    return reinterpret_cast<jobjectArray>(env->CallObjectMethod(m, mid_ptypes));
}

static jstring * ClassArrayToJStrings(JNIEnv *env, jobjectArray arr) {
    jstring * chr;
    int size = env->GetArrayLength(arr);
    chr = static_cast<jstring *>(malloc(size * sizeof(_jstring * *)));
    jmethodID mid_getName = env->GetMethodID(ClassClass, "getName", "()Ljava/lang/String;");
    for (int i = 0; i < size; i++) {
        jobject elem = env->GetObjectArrayElement(arr, i);
        chr[i] = reinterpret_cast<jstring>(env->CallObjectMethod(elem, mid_getName));
    }
    return chr;
}

static void ThrowClass(JNIEnv *env, jclass clazz) {
    jmethodID mid = env->GetMethodID(clazz, "<init>", "()V");
    env->Throw(reinterpret_cast<jthrowable>(env->NewObject(clazz, mid)));
}

static const char * * JStringsToChars(JNIEnv *env, jstring *str, int size) {
    const char ** chr;
    chr = static_cast<const char **>(malloc(size * sizeof(const char *)));
    for (int i = 0; i < size; i++) {
        chr[i] = env->GetStringUTFChars(str[i], nullptr);
    }
    return chr;
}

static jboolean ToBoolean(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassBoolean, "booleanValue", "()Z");
    return env->CallBooleanMethod(obj, id);
}

static jbyte ToByte(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassByte, "byteValue", "()B");
    return env->CallByteMethod(obj, id);
}

static jchar ToCharacter(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassCharacter, "charValue", "()C");
    return env->CallCharMethod(obj, id);
}

static jdouble ToDouble(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassDouble, "doubleValue", "()D");
    return env->CallDoubleMethod(obj, id);
}

static jfloat ToFloat(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassFloat, "floatValue", "()F");
    return env->CallFloatMethod(obj, id);
}

static jint ToInteger(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassInteger, "intValue", "()I");
    return env->CallIntMethod(obj, id);
}

static jlong ToLong(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassLong, "longValue", "()J");
    return env->CallLongMethod(obj, id);
}

static jshort ToShort(JNIEnv *env, jobject obj) {
    jmethodID id = env->GetMethodID(ClassShort, "shortValue", "()S");
    return env->CallShortMethod(obj, id);
}

static jvalue SetValue(JNIEnv *env, jvalue value, jobject obj, const std::string& ps) {
    if (obj == nullptr) {
        value.l = nullptr;
        return value;
    }
    jmethodID mid_getName = env->GetMethodID(ClassClass, "getName", "()Ljava/lang/String;");
    auto str = reinterpret_cast<jstring>(env->CallObjectMethod(env->GetObjectClass(obj), mid_getName));
    auto name = env->GetStringUTFChars(str, nullptr);
    auto s = std::string(name);
    if (s == "java.lang.Boolean") {
        if (ps == "boolean") {
            value.z = ToBoolean(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassBoolean, "valueOf", "(Z)Ljava/lang/Boolean;");
            value.l = env->CallStaticObjectMethod(ClassBoolean, mid, ToBoolean(env, obj));
        }
    } else if (s == "java.lang.Byte") {
        if (ps == "byte") {
            value.b = ToByte(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassByte, "valueOf", "(B)Ljava/lang/Byte;");
            value.l = env->CallStaticObjectMethod(ClassByte, mid, ToByte(env, obj));
        }
    } else if (s == "java.lang.Character") {
        if (ps == "char") {
            value.c = ToCharacter(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassCharacter, "valueOf", "(C)Ljava/lang/Character;");
            value.l = env->CallStaticObjectMethod(ClassCharacter, mid, ToCharacter(env, obj));
        }
    } else if (s == "java.lang.Double") {
        if (ps == "double") {
            value.d = ToDouble(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassDouble, "valueOf", "(D)Ljava/lang/Double;");
            value.l = env->CallStaticObjectMethod(ClassDouble, mid, ToDouble(env, obj));
        }
    } else if (s == "java.lang.Float") {
        if (ps == "float") {
            value.f = ToFloat(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassFloat, "valueOf", "(F)Ljava/lang/Float;");
            value.l = env->CallStaticObjectMethod(ClassFloat, mid, ToFloat(env, obj));
        }
    } else if (s == "java.lang.Integer") {
        if (ps == "int") {
            value.i = ToInteger(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassInteger, "valueOf", "(I)Ljava/lang/Integer;");
            value.l = env->CallStaticObjectMethod(ClassInteger, mid, ToInteger(env, obj));
        }
    } else if (s == "java.lang.Long") {
        if (ps == "long") {
            value.j = ToLong(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassLong, "valueOf", "(J)Ljava/lang/Long;");
            value.l = env->CallStaticObjectMethod(ClassLong, mid, ToLong(env, obj));
        }
    } else if (s == "java.lang.Short") {
        if (ps == "short") {
            value.s = ToShort(env, obj);
        } else {
            jmethodID mid = env->GetStaticMethodID(ClassShort, "valueOf", "(S)Ljava/lang/Short;");
            value.l = env->CallStaticObjectMethod(ClassShort, mid, ToShort(env, obj));
        }
    } else {
        value.l = obj;
    }
    env->ReleaseStringUTFChars(str, name);
    env->DeleteLocalRef(obj);
    return value;
}

static jvalue * TransformParamsToArgs(JNIEnv *env, jobjectArray params, jobject method) {
    jobjectArray arr = GetMethodParams(env, method);
    jstring * str = ClassArrayToJStrings(env, arr);
    jvalue * args;
    int size = env->GetArrayLength(params);
    const char * * chr = JStringsToChars(env, str, size);
    if (size != env->GetArrayLength(arr)) {
        env->ThrowNew(ClassIllegalArgumentException, "Argument count mismatch");
        return nullptr;
    }
    args = static_cast<jvalue *>(malloc(size * sizeof(jvalue)));
    env->EnsureLocalCapacity(size + 5);
    for (int i = 0; i < size; i++) {
        jobject obj = env->GetObjectArrayElement(params, i);
        args[i] = SetValue(env, args[i], obj, std::string(chr[i]));
    }
    for (int i = 0; i < size; i++) {
        env->ReleaseStringUTFChars(str[i], chr[i]);
    }
    free(str);
    free(chr);
    env->DeleteLocalRef(arr);
    env->DeleteLocalRef(params);
    return args;
}

}