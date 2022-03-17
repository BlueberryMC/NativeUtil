package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.NoSuchElementException;

/**
 * NativeAccessor gives you raw access to native methods, without any checks/overheads.
 */
public class NativeAccessor {
    static {
        NativeCode.loadLibrary("libnativeutil");
        init();
    }

    private static native void init();

    public static native void appendToBootstrapClassLoaderSearch(@NotNull String url);
    public static native void appendToSystemClassLoaderSearch(@NotNull String url);
    public static native <T> T allocateInstance(@NotNull Class<T> clazz);
    public static native void setBoolean(@NotNull Field field, @Nullable Object instance, boolean value);
    public static native void setByte(@NotNull Field field, @Nullable Object instance, byte value);
    public static native void setChar(@NotNull Field field, @Nullable Object instance, char value);
    public static native void setDouble(@NotNull Field field, @Nullable Object instance, double value);
    public static native void setFloat(@NotNull Field field, @Nullable Object instance, float value);
    public static native void setInt(@NotNull Field field, @Nullable Object instance, int value);
    public static native void setLong(@NotNull Field field, @Nullable Object instance, long value);
    public static native void setShort(@NotNull Field field, @Nullable Object instance, short value);
    public static native void setObject(@NotNull Field field, @Nullable Object instance, Object value);
    public static native boolean getBoolean(@NotNull Field field, @Nullable Object instance);
    public static native byte getByte(@NotNull Field field, @Nullable Object instance);
    public static native char getChar(@NotNull Field field, @Nullable Object instance);
    public static native double getDouble(@NotNull Field field, @Nullable Object instance);
    public static native float getFloat(@NotNull Field field, @Nullable Object instance);
    public static native int getInt(@NotNull Field field, @Nullable Object instance);
    public static native long getLong(@NotNull Field field, @Nullable Object instance);
    public static native short getShort(@NotNull Field field, @Nullable Object instance);
    public static native Object getObject(@NotNull Field field, @Nullable Object instance);
    public static native void invokeVoid(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native boolean invokeBoolean(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native byte invokeByte(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native char invokeChar(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native double invokeDouble(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native float invokeFloat(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native int invokeInt(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native long invokeLong(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native short invokeShort(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native Object invokeObject(@NotNull Method method, @Nullable Object instance, Object... args);
    public static native void invokeNonvirtualVoid(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native boolean invokeNonvirtualBoolean(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native byte invokeNonvirtualByte(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native char invokeNonvirtualChar(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native double invokeNonvirtualDouble(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native float invokeNonvirtualFloat(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native int invokeNonvirtualInt(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native long invokeNonvirtualLong(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native short invokeNonvirtualShort(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native Object invokeNonvirtualObject(@NotNull Method method, @NotNull Object instance, Object... args);
    public static native <T> T newInstance(@NotNull Constructor<T> method, Object[] args);
    public static native Method getStaticMethod(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException;
    public static native Method getNonstaticMethod(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException;
    public static native Field getStaticField(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException;
    public static native Field getNonstaticField(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException;
    public static native Class<?> defineClass(@NotNull String name, @NotNull ClassLoader classLoader, byte[] buf, int len);
    public static native void forceGarbageCollection();
    public static native Class<?>[] getLoadedClasses();
    public static native Class<?>[] getClassLoaderClasses(@NotNull ClassLoader classLoader);
    public static native void retransformClasses(@NotNull Class<?>[] classes);
    public static native long getObjectSize(@NotNull Object o);
    public static native int getObjectHashcode(@NotNull Object o);
    public static native void registerClassLoadHook(@NotNull ClassLoadHook classLoadHook);
    public static native boolean isModifiableClass(@NotNull Class<?> clazz);
    public static native boolean canRedefineClasses();
    public static native void redefineClasses(@NotNull ClassDefinition[] classDefinition);
}
