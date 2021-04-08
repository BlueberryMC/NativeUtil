#include "net_blueberrymc_native_util_NativeAccessor.h"
#include "jvmti.h"

JavaVM* GetVM(JNIEnv *env) {
    JavaVM *jvm;
    env->GetJavaVM(&jvm);
    return jvm;
}

jvmtiEnv* GetJvmti(JavaVM *jvm) {
    void *ptr;
    jvm->GetEnv(&ptr, JVMTI_VERSION_1_1);
    return (jvmtiEnv*) ptr;
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_appendToBootstrapClassLoaderSearch
        (JNIEnv *env, jclass clazz, jstring url) {
    const char *chars = env->GetStringUTFChars(url, 0);
    GetJvmti(GetVM(env))->AddToBootstrapClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}

JNIEXPORT void JNICALL Java_net_blueberrymc_native_1util_NativeAccessor_appendToSystemClassLoaderSearch
        (JNIEnv *env, jclass clazz, jstring url) {
    const char *chars = env->GetStringUTFChars(url, 0);
    GetJvmti(GetVM(env))->AddToSystemClassLoaderSearch(chars);
    env->ReleaseStringUTFChars(url, chars);
}
