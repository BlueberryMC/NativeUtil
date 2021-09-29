#include "net_blueberrymc_native_util_NativeAccessor.h"
#include "common-tools.cpp"
#include <string>

extern "C" {
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void* reserved) {
    InitCapabilities(vm);
    return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_init
        (JNIEnv *env, jclass) {
    InitTools(env);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_appendToBootstrapClassLoaderSearch
        (JNIEnv *env, jclass, jstring url) {
    const char *chars = env->GetStringUTFChars(url, nullptr);
    GetJvmti(GetVM(env))->AddToBootstrapClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_appendToSystemClassLoaderSearch
        (JNIEnv *env, jclass, jstring url) {
    const char *chars = env->GetStringUTFChars(url, nullptr);
    GetJvmti(GetVM(env))->AddToSystemClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_allocateInstance
        (JNIEnv *env, jclass, jclass clazz) {
    return env->AllocObject(clazz);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setFloat
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jfloat value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticFloatField(clazz, id, value);
    } else {
        env->SetFloatField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setBoolean
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jboolean value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticBooleanField(clazz, id, value);
    } else {
        env->SetBooleanField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setByte
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jbyte value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticByteField(clazz, id, value);
    } else {
        env->SetByteField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setChar
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jchar value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticCharField(clazz, id, value);
    } else {
        env->SetCharField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setDouble
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jdouble value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticDoubleField(clazz, id, value);
    } else {
        env->SetDoubleField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setInt
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jint value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticIntField(clazz, id, value);
    } else {
        env->SetIntField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setLong
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jlong value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticLongField(clazz, id, value);
    } else {
        env->SetLongField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setShort
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jshort value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticShortField(clazz, id, value);
    } else {
        env->SetShortField(instance, id, value);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_setObject
        (JNIEnv *env, jclass clazz, jobject field, jobject instance, jobject value) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        env->SetStaticObjectField(clazz, id, value);
    } else {
        env->SetObjectField(instance, id, value);
    }
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getBoolean
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticBooleanField(clazz, id);
    } else {
        return env->GetBooleanField(instance, id);
    }
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getByte
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticByteField(clazz, id);
    } else {
        return env->GetByteField(instance, id);
    }
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getChar
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticCharField(clazz, id);
    } else {
        return env->GetCharField(instance, id);
    }
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getDouble
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticDoubleField(clazz, id);
    } else {
        return env->GetDoubleField(instance, id);
    }
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getFloat
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticFloatField(clazz, id);
    } else {
        return env->GetFloatField(instance, id);
    }
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getInt
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticIntField(clazz, id);
    } else {
        return env->GetIntField(instance, id);
    }
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getLong
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticLongField(clazz, id);
    } else {
        return env->GetLongField(instance, id);
    }
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getShort
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticShortField(clazz, id);
    } else {
        return env->GetShortField(instance, id);
    }
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getObject
        (JNIEnv *env, jclass clazz, jobject field, jobject instance) {
    jfieldID id = env->FromReflectedField(field);
    if (instance == nullptr) {
        return env->GetStaticObjectField(clazz, id);
    } else {
        return env->GetObjectField(instance, id);
    }
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeVoid
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return;
    }
    env->DeleteLocalRef(method);
    if (instance == nullptr) {
        env->CallStaticVoidMethodA(clazz, id, args);
    } else {
        env->CallVoidMethodA(instance, id, args);
    }
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeBoolean
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jboolean obj;
    if (instance == nullptr) {
        obj = env->CallStaticBooleanMethodA(clazz, id, args);
    } else {
        obj = env->CallBooleanMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeByte
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jbyte obj;
    if (instance == nullptr) {
        obj = env->CallStaticByteMethodA(clazz, id, args);
    } else {
        obj = env->CallByteMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeChar
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jchar obj;
    if (instance == nullptr) {
        obj = env->CallStaticCharMethodA(clazz, id, args);
    } else {
        obj = env->CallCharMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeDouble
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jdouble obj;
    if (instance == nullptr) {
        obj = env->CallStaticDoubleMethodA(clazz, id, args);
    } else {
        obj = env->CallDoubleMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeFloat
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jfloat obj;
    if (instance == nullptr) {
        obj = env->CallStaticFloatMethodA(clazz, id, args);
    } else {
        obj = env->CallFloatMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeInt
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jint obj;
    if (instance == nullptr) {
        obj = env->CallStaticIntMethodA(clazz, id, args);
    } else {
        obj = env->CallIntMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeLong
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jlong obj;
    if (instance == nullptr) {
        obj = env->CallStaticLongMethodA(clazz, id, args);
    } else {
        obj = env->CallLongMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeShort
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) {
        return 0;
    }
    env->DeleteLocalRef(method);
    jshort obj;
    if (instance == nullptr) {
        obj = env->CallStaticShortMethodA(clazz, id, args);
    } else {
        obj = env->CallShortMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeObject
        (JNIEnv *env, jclass clazz, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    env->DeleteLocalRef(method);
    if (args == nullptr) return nullptr;
    jobject obj;
    if (instance == nullptr) {
        obj = env->CallStaticObjectMethodA(clazz, id, args);
    } else {
        obj = env->CallObjectMethodA(instance, id, args);
    }
    free(args);
    return obj;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualVoid
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return;
    env->CallNonvirtualVoidMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualBoolean
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jboolean obj = env->CallNonvirtualBooleanMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualByte
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jbyte obj = env->CallNonvirtualByteMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jchar JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualChar
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jchar obj = env->CallNonvirtualCharMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualDouble
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jdouble obj = env->CallNonvirtualDoubleMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualFloat
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jfloat obj = env->CallNonvirtualFloatMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualInt
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jint obj = env->CallNonvirtualIntMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualLong
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jlong obj = env->CallNonvirtualLongMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jshort JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualShort
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return 0;
    jshort obj = env->CallNonvirtualShortMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_invokeNonvirtualObject
        (JNIEnv *env, jclass, jobject method, jobject instance, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(method);
    jvalue *args = TransformParamsToArgs(env, params, method);
    if (args == nullptr) return nullptr;
    jobject obj = env->CallNonvirtualObjectMethodA(instance, GetDeclaringClass(env, method), id, args);
    env->DeleteLocalRef(method);
    free(args);
    return obj;
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_newInstance
        (JNIEnv *env, jclass, jobject ctor, jobjectArray params) {
    jmethodID id = env->FromReflectedMethod(ctor);
    jvalue *args = TransformParamsToArgs(env, params, ctor);
    if (args == nullptr) return nullptr;
    jclass cl = GetDeclaringClass(env, ctor);
    env->DeleteLocalRef(ctor);
    if (cl == nullptr) {
        return nullptr;
    }
    jobject obj = env->NewObjectA(cl, id, args);
    free(args);
    return obj;
}

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getStaticMethod
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

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getNonstaticMethod
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

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getStaticField
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

JNIEXPORT jobject JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getNonstaticField
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

JNIEXPORT jclass JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_defineClass
        (JNIEnv *env, jclass, jstring name, jobject classLoader, jbyteArray buf, jint len) {
    jbyte * byteBuf = env->GetByteArrayElements(buf, nullptr);
    const char * n = env->GetStringUTFChars(name, nullptr);
    jclass clazz = env->DefineClass(n, classLoader, byteBuf, len);
    env->ReleaseStringUTFChars(name, n);
    env->ReleaseByteArrayElements(buf, byteBuf, 0);
    return clazz;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_forceGarbageCollection
        (JNIEnv *env, jclass) {
    GetJvmti(GetVM(env))->ForceGarbageCollection();
}

JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getLoadedClasses
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

JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getClassLoaderClasses
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

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_retransformClasses
        (JNIEnv *env, jclass, jobjectArray arr) {
    jclass * clazz;
    int size = env->GetArrayLength(arr);
    clazz = static_cast<jclass *>(malloc(size * sizeof(_jclass)));
    for (int i = 0; i < size; ++i) {
        clazz[i] = reinterpret_cast<jclass>(env->GetObjectArrayElement(arr, i));
    }
    GetJvmti(GetVM(env))->RetransformClasses(size, clazz);
}

JNIEXPORT jlong JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getObjectSize
        (JNIEnv *env, jclass, jobject o) {
    jlong size;
    GetJvmti(GetVM(env))->GetObjectSize(o, &size);
    return size;
}

JNIEXPORT jint JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_getObjectHashcode
        (JNIEnv *env, jclass, jobject o) {
    jint hashcode;
    GetJvmti(GetVM(env))->GetObjectHashCode(o, &hashcode);
    return hashcode;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_registerClassLoadHook
        (JNIEnv *env, jclass, jobject obj) {
    AddClassLoadHook(env, obj);
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_isModifiableClass
        (JNIEnv *env, jclass, jclass clazz) {
    jboolean isModifiable;
    GetJvmti(GetVM(env))->IsModifiableClass(reinterpret_cast<jclass>(clazz), &isModifiable);
    return isModifiable;
}

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_canRedefineClasses
        (JNIEnv *env, jclass) {
    jvmtiCapabilities caps;
    int err = GetJvmti(GetVM(env))->GetCapabilities(&caps);
    if (err != JVMTI_ERROR_NONE) {
        env->ThrowNew(ClassNativeException, concat("Failed to get capabilities: ", err).c_str());
    }
    return caps.can_redefine_classes;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_redefineClasses
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
        definitions[i] = {
                clazz,
                length,
                bytes,
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
}
