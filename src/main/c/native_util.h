/* DO ~~NOT~~ EDIT THIS FILE - it is (not) machine generated */
#include <jni.h>
/* Header for class net_blueberrymc_nativeutil_NativeAccessor */

#ifndef _Included_net_blueberrymc_nativeutil_NativeAccessor
#define _Included_net_blueberrymc_nativeutil_NativeAccessor
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_init
  (JNIEnv *, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    appendToBootstrapClassLoaderSearch
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_appendToBootstrapClassLoaderSearch
  (JNIEnv *, jclass, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    appendToSystemClassLoaderSearch
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_appendToSystemClassLoaderSearch
  (JNIEnv *, jclass, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    allocateInstance
 * Signature: (Ljava/lang/Class;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_allocateInstance
  (JNIEnv *, jclass, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setBoolean
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;Z)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setBoolean
  (JNIEnv *, jclass, jobject, jobject, jboolean);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setByte
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;B)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setByte
  (JNIEnv *, jclass, jobject, jobject, jbyte);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setChar
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;C)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setChar
  (JNIEnv *, jclass, jobject, jobject, jchar);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setDouble
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;D)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setDouble
  (JNIEnv *, jclass, jobject, jobject, jdouble);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setFloat
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;F)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setFloat
  (JNIEnv *, jclass, jobject, jobject, jfloat);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setInt
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;I)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setInt
  (JNIEnv *, jclass, jobject, jobject, jint);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setLong
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;J)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setLong
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setShort
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;S)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setShort
  (JNIEnv *, jclass, jobject, jobject, jshort);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    setObject
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setObject
  (JNIEnv *, jclass, jobject, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getBoolean
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getBoolean
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getByte
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)B
 */
JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getByte
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getChar
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)C
 */
JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getChar
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getDouble
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)D
 */
JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getDouble
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getFloat
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)F
 */
JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getFloat
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getInt
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getInt
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getLong
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)J
 */
JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getLong
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getShort
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)S
 */
JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getShort
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getObject
 * Signature: (Ljava/lang/reflect/Field;Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObject
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeVoid
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeVoid
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeBoolean
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeBoolean
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeByte
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)B
 */
JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeByte
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeChar
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)C
 */
JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeChar
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeDouble
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)D
 */
JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeDouble
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeFloat
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)F
 */
JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeFloat
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeInt
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeInt
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeLong
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)J
 */
JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeLong
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeShort
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)S
 */
JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeShort
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeObject
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeObject
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualVoid
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualVoid
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualBoolean
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualBoolean
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualByte
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)B
 */
JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualByte
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualChar
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)C
 */
JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualChar
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualDouble
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)D
 */
JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualDouble
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualFloat
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)F
 */
JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualFloat
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualInt
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualInt
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualLong
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)J
 */
JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualLong
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualShort
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)S
 */
JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualShort
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    invokeNonvirtualObject
 * Signature: (Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_invokeNonvirtualObject
  (JNIEnv *, jclass, jobject, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    newInstance
 * Signature: (Ljava/lang/reflect/Constructor;[Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_newInstance
  (JNIEnv *, jclass, jobject, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getStaticMethod
 * Signature: (Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/reflect/Method;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getStaticMethod
  (JNIEnv *, jclass, jclass, jstring, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getNonstaticMethod
 * Signature: (Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/reflect/Method;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getNonstaticMethod
  (JNIEnv *, jclass, jclass, jstring, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getStaticField
 * Signature: (Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/reflect/Field;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getStaticField
  (JNIEnv *, jclass, jclass, jstring, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getNonstaticField
 * Signature: (Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/reflect/Field;
 */
JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getNonstaticField
  (JNIEnv *, jclass, jclass, jstring, jstring);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    defineClass
 * Signature: (Ljava/lang/String;Ljava/lang/ClassLoader;[BI)Ljava/lang/Class;
 */
JNIEXPORT jclass JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_defineClass
  (JNIEnv *, jclass, jstring, jobject, jbyteArray, jint);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    forceGarbageCollection
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_forceGarbageCollection
  (JNIEnv *, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getLoadedClasses
 * Signature: ()[Ljava/lang/Class;
 */
JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getLoadedClasses
  (JNIEnv *, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getClassLoaderClasses
 * Signature: (Ljava/lang/ClassLoader;)[Ljava/lang/Class;
 */
JNIEXPORT jobjectArray JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getClassLoaderClasses
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    retransformClasses
 * Signature: ([Ljava/lang/Class;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_retransformClasses
  (JNIEnv *, jclass, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getObjectSize
 * Signature: (Ljava/lang/Object;)J
 */
JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObjectSize
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getObjectHashcode
 * Signature: (Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getObjectHashcode
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    registerClassLoadHook
 * Signature: (Lnet/blueberrymc/nativeutil/ClassLoadHook;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_registerClassLoadHook
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    isModifiableClass
 * Signature: (Ljava/lang/Class;)Z
 */
JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_isModifiableClass
  (JNIEnv *, jclass, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    canRedefineClasses
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_canRedefineClasses
  (JNIEnv *, jclass);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    redefineClasses
 * Signature: ([Lnet/blueberrymc/nativeutil/ClassDefinition;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_redefineClasses
  (JNIEnv *, jclass, jobjectArray);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    getMethodId
 * Signature: (Ljava/lang/reflect/Method;)J
 */
JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getMethodId
        (JNIEnv *, jclass, jobject);

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getMethodFromId
        (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     net_blueberrymc_nativeutil_NativeAccessor
 * Method:    callVoid
 * Signature: (JLjava/lang/Object;[Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callVoid
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callBoolean
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callByte
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callChar
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callDouble
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callFloat
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callInt
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callLong
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callShort
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callObject
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualVoid
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jboolean JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualBoolean
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jbyte JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualByte
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jchar JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualChar
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jdouble JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualDouble
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jfloat JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualFloat
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jint JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualInt
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualLong
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jshort JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualShort
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT jobject JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_callNonvirtualObject
        (JNIEnv *, jclass, jlong, jobject, jobjectArray);

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_free
        (JNIEnv *, jclass, jlong);

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_memset
        (JNIEnv *, jclass, jlong, jint, jint);

JNIEXPORT jlong JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_getCurrentThreadAddress
        (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_net_blueberrymc_nativeutil_NativeAccessor_setAffinity
        (JNIEnv *, jclass, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
