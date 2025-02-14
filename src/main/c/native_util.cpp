#include "native_util.h"
#include "common_tools.cpp"
#include <cstring>
#include <string>
#include <jni.h>
#include <stdio.h>
#include <cstdint>

#ifdef __linux__
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

struct ThreadInfo {
  pthread_t thread;
};
#endif

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#define CALL_METHOD(jtype, type) \
  if (env->GetArrayLength(params) == 0) { \
    if (instance == nullptr) { \
      return env->CallStatic##type##Method(clazz, id); \
    } else { \
      return env->Call##type##Method(instance, id); \
    } \
  } \
  jvalue *args = TransformParams(env, params); \
  jtype obj; \
  if (instance == nullptr) { \
    obj = env->CallStatic##type##MethodA(clazz, id, args); \
  } else { \
    obj = env->Call##type##MethodA(instance, id, args); \
  } \
  free(args); \
  return obj;

#define CALL_NONVIRTUAL_METHOD(jtype, type) \
  if (env->GetArrayLength(params) == 0) { \
    return env->CallNonvirtual##type##Method(instance, klass, id); \
  } \
  jvalue *args = TransformParams(env, params); \
  jtype obj = env->CallNonvirtual##type##MethodA(instance, klass, id, args); \
  free(args); \
  return obj;

struct MethodIDInfo {
  jmethodID id;
  jclass klass;
};

extern "C" {
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void* reserved) {
    InitCapabilities(vm);
    return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_init
        (JNIEnv *env, jclass) {
    InitTools(env);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_appendToBootstrapClassLoaderSearch
        (JNIEnv *env, jclass, jstring url) {
    const char *chars = env->GetStringUTFChars(url, nullptr);
    GetJvmti(GetVM(env))->AddToBootstrapClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_appendToSystemClassLoaderSearch
        (JNIEnv *env, jclass, jstring url) {
    const char *chars = env->GetStringUTFChars(url, nullptr);
    GetJvmti(GetVM(env))->AddToSystemClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_allocateInstance
        (JNIEnv *env, jclass, jclass clazz) {
    return env->AllocObject(clazz);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setFloat
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jfloat value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticFloatField(clazz, id, value);
    } else {
        env->SetFloatField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setBoolean
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jboolean value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticBooleanField(clazz, id, value);
    } else {
        env->SetBooleanField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setByte
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jbyte value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticByteField(clazz, id, value);
    } else {
        env->SetByteField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setChar
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jchar value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticCharField(clazz, id, value);
    } else {
        env->SetCharField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setDouble
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jdouble value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticDoubleField(clazz, id, value);
    } else {
        env->SetDoubleField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setInt
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jint value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticIntField(clazz, id, value);
    } else {
        env->SetIntField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setLong
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jlong value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticLongField(clazz, id, value);
    } else {
        env->SetLongField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setShort
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jshort value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticShortField(clazz, id, value);
    } else {
        env->SetShortField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setObject
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jobject value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticObjectField(clazz, id, value);
    } else {
        env->SetObjectField(instance, id, value);
    }
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getBoolean
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticBooleanField(clazz, id);
    } else {
        return env->GetBooleanField(instance, id);
    }
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getByte
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticByteField(clazz, id);
    } else {
        return env->GetByteField(instance, id);
    }
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getChar
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticCharField(clazz, id);
    } else {
        return env->GetCharField(instance, id);
    }
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getDouble
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticDoubleField(clazz, id);
    } else {
        return env->GetDoubleField(instance, id);
    }
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getFloat
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticFloatField(clazz, id);
    } else {
        return env->GetFloatField(instance, id);
    }
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getInt
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticIntField(clazz, id);
    } else {
        return env->GetIntField(instance, id);
    }
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getLong
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticLongField(clazz, id);
    } else {
        return env->GetLongField(instance, id);
    }
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getShort
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticShortField(clazz, id);
    } else {
        return env->GetShortField(instance, id);
    }
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObject
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticObjectField(clazz, id);
    } else {
        return env->GetObjectField(instance, id);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeVoid
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    if (env->GetArrayLength(params) == 0) {
        if (instance == nullptr) {
            env->CallStaticVoidMethod(clazz, id);
        } else {
            env->CallVoidMethod(instance, id);
        }
        return;
    }
    jvalue *args = TransformParams(env, params);
    if (instance == nullptr) {
        env->CallStaticVoidMethodA(clazz, id, args);
    } else {
        env->CallVoidMethodA(instance, id, args);
    }
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeBoolean
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jboolean, Boolean)
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeByte
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jbyte, Byte)
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeChar
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jchar, Char)
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeDouble
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jdouble, Double)
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeFloat
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jfloat, Float)
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeInt
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jint, Int)
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeLong
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jlong, Long)
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeShort
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jshort, Short)
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeObject
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    CALL_METHOD(jobject, Object)
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualVoid
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParams(env, params);
    if (args == nullptr) return;
    env->CallNonvirtualVoidMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualBoolean
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jboolean, Boolean)
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualByte
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jbyte, Byte)
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualChar
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jchar, Char)
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualDouble
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jdouble, Double)
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualFloat
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jfloat, Float)
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualInt
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jint, Int)
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualLong
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jlong, Long)
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualShort
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jshort, Short)
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualObject
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    CALL_NONVIRTUAL_METHOD(jobject, Object)
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_newInstance
        (JNIEnv *env, jclass, jobject ctor, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(ctor);
    jvalue *args = TransformParams(env, params);
    jclass cl = GetDeclaringClass(env, ctor);
    if (cl == nullptr) {
        return nullptr;
    }
    jobject obj = env->NewObjectA(cl, id, args);
    free(args);
    return obj;
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getStaticMethod
        (JNIEnv *env, jclass, jclass clazz, jstring name, jstring signature) {
    const char * n = env->GetStringUTFChars(name, nullptr);
    const char * s = env->GetStringUTFChars(signature, nullptr);
    jmethodID mid = env->GetStaticMethodID(clazz, n, s);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseStringUTFChars(signature, s);
    if (mid == nullptr) {
        ThrowClass(env, ClassNoSuchElementException);
        return nullptr;
    } else {
        return env->ToReflectedMethod(clazz, mid, true);
    }
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getNonstaticMethod
        (JNIEnv *env, jclass, jclass clazz, jstring name, jstring signature) {
    const char * n = env->GetStringUTFChars(name, nullptr);
    const char * s = env->GetStringUTFChars(signature, nullptr);
    jmethodID mid = env->GetMethodID(clazz, n, s);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseStringUTFChars(signature, s);
    if (mid == nullptr) {
        ThrowClass(env, ClassNoSuchElementException);
        return nullptr;
    } else {
        return env->ToReflectedMethod(clazz, mid, false);
    }
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getStaticField
        (JNIEnv *env, jclass, jclass clazz, jstring name, jstring signature) {
    const char * n = env->GetStringUTFChars(name, nullptr);
    const char * s = env->GetStringUTFChars(signature, nullptr);
    jfieldID fid = env->GetStaticFieldID(clazz, n, s);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseStringUTFChars(signature, s);
    if (fid == nullptr) {
        ThrowClass(env, ClassNoSuchElementException);
        return nullptr;
    } else {
        return env->ToReflectedField(clazz, fid, true);
    }
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getNonstaticField
        (JNIEnv *env, jclass, jclass clazz, jstring name, jstring signature) {
    const char * n = env->GetStringUTFChars(name, nullptr);
    const char * s = env->GetStringUTFChars(signature, nullptr);
    jfieldID fid = env->GetFieldID(clazz, n, s);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseStringUTFChars(signature, s);
    if (fid == nullptr) {
        ThrowClass(env, ClassNoSuchElementException);
        return nullptr;
    } else {
        return env->ToReflectedField(clazz, fid, false);
    }
}

JNIEXPORT jclass JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_defineClass
        (JNIEnv *env, jclass, jstring name, jobject classLoader, jbyteArray buf, jint len) {
    jbyte * byte_buf = env->GetByteArrayElements(buf, nullptr);
    const char * n = env->GetStringUTFChars(name, nullptr);
    jclass clazz = env->DefineClass(n, classLoader, byte_buf, len);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseByteArrayElements(buf, byte_buf, 0);
    return clazz;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_forceGarbageCollection
        (JNIEnv *env, jclass) {
    GetJvmti(GetVM(env))->ForceGarbageCollection();
}

JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getLoadedClasses
        (JNIEnv *env, jclass) {
    jint count;
    jclass * classes;
    GetJvmti(GetVM(env))->GetLoadedClasses(&count, &classes);
    jobjectArray arr = env->NewObjectArray(count, ClassClass, nullptr);
    for (int i = 0; i < count; ++i) {
        env->SetObjectArrayElement(arr, i, classes[i]);
    }
    return arr;
}

JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getClassLoaderClasses
        (JNIEnv *env, jclass, jobject classLoader) {
    jint count;
    jclass * classes;
    GetJvmti(GetVM(env))->GetClassLoaderClasses(classLoader, &count, &classes);
    jobjectArray arr = env->NewObjectArray(count, ClassClass, nullptr);
    for (int i = 0; i < count; ++i) {
        env->SetObjectArrayElement(arr, i, classes[i]);
    }
    return arr;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_retransformClasses
        (JNIEnv *env, jclass, jobjectArray arr) {
    jclass * clazz;
    int size = env->GetArrayLength(arr);
    clazz = static_cast<jclass *>(malloc(size * sizeof(_jclass)));
    for (int i = 0; i < size; ++i) {
        clazz[i] = reinterpret_cast<jclass>(env->GetObjectArrayElement(arr, i));
    }
    GetJvmti(GetVM(env))->RetransformClasses(size, clazz);
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObjectSize
        (JNIEnv *env, jclass, jobject o) {
    jlong size;
    GetJvmti(GetVM(env))->GetObjectSize(o, &size);
    return size;
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObjectHashcode
        (JNIEnv *env, jclass, jobject o) {
    jint hashcode;
    GetJvmti(GetVM(env))->GetObjectHashCode(o, &hashcode);
    return hashcode;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_registerClassLoadHook
        (JNIEnv *env, jclass, jobject obj) {
    AddClassLoadHook(env, obj);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_isModifiableClass
        (JNIEnv *env, jclass, jclass clazz) {
    jboolean isModifiable;
    GetJvmti(GetVM(env))->IsModifiableClass(clazz, &isModifiable);
    return isModifiable;
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_canRedefineClasses
        (JNIEnv *env, jclass) {
    jvmtiCapabilities caps;
    int err = GetJvmti(GetVM(env))->GetCapabilities(&caps);
    if (err != JVMTI_ERROR_NONE) {
        env->ThrowNew(ClassNativeException, concat("Failed to get capabilities: ", err).c_str());
    }
    return caps.can_redefine_classes;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_redefineClasses
        (JNIEnv *env, jclass, jobjectArray array) {
    jint count = env->GetArrayLength(array);
    if (count == 0) return;
    auto definitions = static_cast<jvmtiClassDefinition *>(malloc(count * sizeof(jvmtiClassDefinition)));
    for (int i = 0; i < count; ++i) {
        jobject obj = env->GetObjectArrayElement(array, i);
        if (obj == nullptr) {
            env->ThrowNew(ClassIllegalArgumentException, "ClassDefinition cannot be null");
            free(definitions);
            return;
        }
        auto clazz = reinterpret_cast<jclass>(env->GetObjectField(obj, ClassClassDefinition_clazz));
        auto arr = reinterpret_cast<jbyteArray>(env->GetObjectField(obj, ClassClassDefinition_bytes));
        jint length = env->GetArrayLength(arr);
        auto bytes = new unsigned char[length];
        env->GetByteArrayRegion(arr, 0, length, reinterpret_cast<jbyte *>(bytes));
        definitions[i] = jvmtiClassDefinition {
                clazz,
                length,
                bytes
        };
    }
    int err = GetJvmti(GetVM(env))->RedefineClasses(count, definitions);
    if (err != 0) {
        if (err == JVMTI_ERROR_UNMODIFIABLE_CLASS) {
            env->ThrowNew(ClassNativeException, "One or more class definition cannot be modified");
        } else if (err == JVMTI_ERROR_INVALID_CLASS) {
            env->ThrowNew(ClassNativeException, "One or more class definition is not a valid class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_VERSION) {
            env->ThrowNew(ClassNativeException, "A new class file has a version number not supported by this VM");
        } else if (err == JVMTI_ERROR_INVALID_CLASS_FORMAT) {
            ThrowClass(env, ClassClassFormatError);
        } else if (err == JVMTI_ERROR_CIRCULAR_CLASS_DEFINITION) {
            ThrowClass(env, ClassClassCircularityError);
        } else if (err == JVMTI_ERROR_FAILS_VERIFICATION) {
            env->ThrowNew(ClassNativeException, "The class bytes failed verification");
        } else if (err == JVMTI_ERROR_NAMES_DONT_MATCH) {
            env->ThrowNew(ClassNativeException, "Class name mismatch");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_METHOD_ADDED) {
            env->ThrowNew(ClassNativeException, "Method cannot be added while redefining a class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_SCHEMA_CHANGED) {
            env->ThrowNew(ClassNativeException, "Field cannot be changed while redefining a class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_HIERARCHY_CHANGED) {
            env->ThrowNew(ClassNativeException, "Hierarchy cannot be changed while redefining a class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_METHOD_DELETED) {
            env->ThrowNew(ClassNativeException, "Method cannot be removed while redefining a class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_CLASS_MODIFIERS_CHANGED) {
            env->ThrowNew(ClassNativeException, "Class modifiers cannot be changed while redefining a class");
        } else if (err == JVMTI_ERROR_UNSUPPORTED_REDEFINITION_METHOD_MODIFIERS_CHANGED) {
            env->ThrowNew(ClassNativeException, "Method modifiers cannot be changed while redefining a class");
        } else {
            env->ThrowNew(ClassNativeException, concat("Failed to redefine classes: ", err).c_str());
        }
        return;
    }
    for (int i = 0; i < count; ++i) {
        delete[] definitions[i].class_bytes;
    }
    free(definitions);
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getMethodId
        (JNIEnv *env, jclass, jobject method) {
    jmethodID m = env->FromReflectedMethod(method);
    jclass klass = GetDeclaringClass(env, method);
    auto *info = new MethodIDInfo {
            m,
            klass
    };
    return addr_to_java(info);
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getMethodFromId
        (JNIEnv *env, jclass, jlong method, jboolean is_static) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(method));
    return env->ToReflectedMethod(info.klass, info.id, is_static);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callVoid
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    if (env->GetArrayLength(params) == 0) {
        if (instance == nullptr) {
            env->CallStaticVoidMethod(clazz, id);
        } else {
            env->CallVoidMethod(instance, id);
        }
        return;
    }
    jvalue *args = TransformParams(env, params);
    if (instance == nullptr) {
        env->CallStaticVoidMethodA(clazz, id, args);
    } else {
        env->CallVoidMethodA(instance, id, args);
    }
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callBoolean
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jboolean, Boolean)
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callByte
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jbyte, Byte)
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callChar
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jchar, Char)
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callDouble
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jdouble, Double)
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callFloat
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jfloat, Float)
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callInt
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jint, Int)
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callLong
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jlong, Long)
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callShort
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jshort, Short)
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callObject
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    CALL_METHOD(jobject, Object)
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualVoid
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    if (env->GetArrayLength(params) == 0) {
        env->CallNonvirtualVoidMethod(instance, klass, id);
        return;
    }
    jvalue *args = TransformParams(env, params);
    env->CallNonvirtualVoidMethodA(instance, klass, id, args);
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualBoolean
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jboolean, Boolean)
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualByte
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jbyte, Byte)
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualChar
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jchar, Char)
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualDouble
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jdouble, Double)
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualFloat
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jfloat, Float)
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualInt
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jint, Int)
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualLong
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jlong, Long)
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualShort
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jshort, Short)
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualObject
        (JNIEnv *env, jclass clazz, jlong methodID, jobject instance, jobjectArray params) {
    MethodIDInfo info = *static_cast<MethodIDInfo *>(addr_from_java(methodID));
    jmethodID id = info.id;
    jclass klass = info.klass;
    CALL_NONVIRTUAL_METHOD(jobject, Object)
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_free
        (JNIEnv *, jclass, jlong address) {
    free(addr_from_java(address));
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_memset
        (JNIEnv *, jclass, jlong address, jint value, jint size) {
    return addr_to_java(memset(addr_from_java(address), value, size));
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getCurrentThreadAddress(JNIEnv * env, jclass) {
    #ifdef __linux__
    pthread_t self = pthread_self();
    auto *threadinfo = new ThreadInfo {
            self
    };
    return addr_to_java(threadinfo);
    #else
    env->ThrowNew(ClassNativeException, "This function only works on Linux");
    return 0;
    #endif
}

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setAffinity
        (JNIEnv * env, jclass, jlong threadId, jint cpuId) {
    #ifdef __linux__
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpuId, &cpuset);

    ThreadInfo *info = static_cast<ThreadInfo *>(addr_from_java(threadId));
    pthread_t thread = info->thread;
    int result = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (result != 0) {
        perror("pthread_setaffinity_np failed");
    }
    #else
    env->ThrowNew(ClassNativeException, "This function only works on Linux");
    #endif
}

}
