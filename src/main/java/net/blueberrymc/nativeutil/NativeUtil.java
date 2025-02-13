package net.blueberrymc.nativeutil;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.io.File;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.net.MalformedURLException;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Optional;
import java.util.jar.JarFile;

@SuppressWarnings("unused")
public class NativeUtil {
    @Contract(pure = true)
    private static @Nullable Void getVoid() {
        return null;
    }

    public static void appendToBootstrapClassLoaderSearch(@NotNull File file) {
        try {
            appendToBootstrapClassLoaderSearch(file.toURI().toURL().toString());
        } catch (MalformedURLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Adds an url to bootstrap class loader.
     * @param url an url to add
     * @see java.lang.instrument.Instrumentation#appendToBootstrapClassLoaderSearch(JarFile)
     */
    public static void appendToBootstrapClassLoaderSearch(@NotNull String url) {
        Objects.requireNonNull(url);
        NativeAccessor.appendToBootstrapClassLoaderSearch(url);
    }

    public static void appendToSystemClassLoaderSearch(@NotNull File file) {
        try {
            appendToSystemClassLoaderSearch(file.toURI().toURL().toString());
        } catch (MalformedURLException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Adds an url to system class loader.
     * @param url an url to add
     * @see java.lang.instrument.Instrumentation#appendToSystemClassLoaderSearch(JarFile)
     */
    public static void appendToSystemClassLoaderSearch(@NotNull String url) {
        Objects.requireNonNull(url);
        NativeAccessor.appendToSystemClassLoaderSearch(url);
    }

    /**
     * Creates new instance without calling constructor of it. See: sun.misc.Unsafe#allocateInstance(Class)
     * @param clazz the class
     * @param <T> the type of the class/instance
     * @return the created instance
     */
    public static <T> T allocateInstance(Class<T> clazz) {
        Objects.requireNonNull(clazz);
        return NativeAccessor.allocateInstance(clazz);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setBoolean(@NotNull Field field, @Nullable Object instance, boolean value) {
        Objects.requireNonNull(field);
        NativeAccessor.setBoolean(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setByte(@NotNull Field field, @Nullable Object instance, byte value) {
        Objects.requireNonNull(field);
        NativeAccessor.setByte(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setChar(@NotNull Field field, @Nullable Object instance, char value) {
        Objects.requireNonNull(field);
        NativeAccessor.setChar(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setDouble(@NotNull Field field, @Nullable Object instance, double value) {
        Objects.requireNonNull(field);
        NativeAccessor.setDouble(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setFloat(@NotNull Field field, @Nullable Object instance, float value) {
        Objects.requireNonNull(field);
        NativeAccessor.setFloat(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setInt(@NotNull Field field, @Nullable Object instance, int value) {
        Objects.requireNonNull(field);
        NativeAccessor.setInt(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setLong(@NotNull Field field, @Nullable Object instance, long value) {
        Objects.requireNonNull(field);
        NativeAccessor.setLong(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setShort(@NotNull Field field, @Nullable Object instance, short value) {
        Objects.requireNonNull(field);
        NativeAccessor.setShort(field, instance, value);
    }

    /**
     * Set value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     * @param value the new value of field
     */
    public static void setObject(@NotNull Field field, @Nullable Object instance, Object value) {
        Objects.requireNonNull(field);
        NativeAccessor.setObject(field, instance, value);
    }

    public static void set(@NotNull Field field, @Nullable Object instance, Object value) {
        Objects.requireNonNull(field);
        if (field.getType() == boolean.class) {
            NativeAccessor.setBoolean(field, instance, (boolean) value);
        } else if (field.getType() == byte.class) {
            NativeAccessor.setByte(field, instance, (byte) value);
        } else if (field.getType() == char.class) {
            NativeAccessor.setChar(field, instance, (char) value);
        } else if (field.getType() == double.class) {
            NativeAccessor.setDouble(field, instance, (double) value);
        } else if (field.getType() == float.class) {
            NativeAccessor.setFloat(field, instance, (float) value);
        } else if (field.getType() == int.class) {
            NativeAccessor.setInt(field, instance, (int) value);
        } else if (field.getType() == long.class) {
            NativeAccessor.setLong(field, instance, (long) value);
        } else if (field.getType() == short.class) {
            NativeAccessor.setShort(field, instance, (short) value);
        } else {
            NativeAccessor.setObject(field, instance, value);
        }
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static boolean getBoolean(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getBoolean(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static byte getByte(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getByte(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static char getChar(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getChar(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static double getDouble(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getDouble(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static float getFloat(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getFloat(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static int getInt(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getInt(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static long getLong(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getLong(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * @param field the field
     * @param instance the instance
     */
    public static short getShort(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getShort(field, instance);
    }

    /**
     * Get value of a field without calling {@link Field#setAccessible(boolean)}.
     * <p><strong>WARNING: If you are trying to call this method with a field of primitive type, you should rethink your life.</strong>
     * @param field the field
     * @param instance the instance
     */
    public static Object getObject(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        return NativeAccessor.getObject(field, instance);
    }

    public static Object get(@NotNull Field field, @Nullable Object instance) {
        Objects.requireNonNull(field);
        if (field.getType() == boolean.class) {
            return NativeAccessor.getBoolean(field, instance);
        } else if (field.getType() == byte.class) {
            return NativeAccessor.getByte(field, instance);
        } else if (field.getType() == char.class) {
            return NativeAccessor.getChar(field, instance);
        } else if (field.getType() == double.class) {
            return NativeAccessor.getDouble(field, instance);
        } else if (field.getType() == float.class) {
            return NativeAccessor.getFloat(field, instance);
        } else if (field.getType() == int.class) {
            return NativeAccessor.getInt(field, instance);
        } else if (field.getType() == long.class) {
            return NativeAccessor.getLong(field, instance);
        } else if (field.getType() == short.class) {
            return NativeAccessor.getShort(field, instance);
        } else {
            return NativeAccessor.getObject(field, instance);
        }
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static void invokeVoid(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        NativeAccessor.invokeVoid(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static boolean invokeBoolean(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeBoolean(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static byte invokeByte(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeByte(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static char invokeChar(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeChar(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static double invokeDouble(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeDouble(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static float invokeFloat(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeFloat(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static int invokeInt(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeInt(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static long invokeLong(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeLong(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static short invokeShort(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeShort(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static Object invokeObject(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        return NativeAccessor.invokeObject(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    @Contract("_, _, _ -> _")
    public static Object invoke(@NotNull Method method, @Nullable Object instance, Object... args) {
        Objects.requireNonNull(method);
        if (method.getReturnType() == void.class) {
            invokeVoid(method, instance, args);
            return getVoid();
        } else if (method.getReturnType() == boolean.class) {
            return NativeAccessor.invokeBoolean(method, instance, args);
        } else if (method.getReturnType() == byte.class) {
            return NativeAccessor.invokeByte(method, instance, args);
        } else if (method.getReturnType() == char.class) {
            return NativeAccessor.invokeChar(method, instance, args);
        } else if (method.getReturnType() == double.class) {
            return NativeAccessor.invokeDouble(method, instance, args);
        } else if (method.getReturnType() == float.class) {
            return NativeAccessor.invokeFloat(method, instance, args);
        } else if (method.getReturnType() == int.class) {
            return NativeAccessor.invokeInt(method, instance, args);
        } else if (method.getReturnType() == long.class) {
            return NativeAccessor.invokeLong(method, instance, args);
        } else if (method.getReturnType() == short.class) {
            return NativeAccessor.invokeShort(method, instance, args);
        } else {
            return NativeAccessor.invokeObject(method, instance, args);
        }
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static void invokeNonvirtualVoid(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        NativeAccessor.invokeNonvirtualVoid(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static boolean invokeNonvirtualBoolean(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualBoolean(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static byte invokeNonvirtualByte(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualByte(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static char invokeNonvirtualChar(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualChar(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static double invokeNonvirtualDouble(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualDouble(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static float invokeNonvirtualFloat(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualFloat(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static int invokeNonvirtualInt(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualInt(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static long invokeNonvirtualLong(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualLong(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static short invokeNonvirtualShort(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualShort(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static Object invokeNonvirtualObject(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        return NativeAccessor.invokeNonvirtualObject(method, instance, args);
    }

    /**
     * Invoke a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    @Contract("_, _, _ -> _")
    public static Object invokeNonvirtual(@NotNull Method method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(method);
        Objects.requireNonNull(instance);
        if (method.getReturnType() == void.class) {
            invokeNonvirtualVoid(method, instance, args);
            return getVoid();
        } else if (method.getReturnType() == boolean.class) {
            return NativeAccessor.invokeNonvirtualBoolean(method, instance, args);
        } else if (method.getReturnType() == byte.class) {
            return NativeAccessor.invokeNonvirtualByte(method, instance, args);
        } else if (method.getReturnType() == char.class) {
            return NativeAccessor.invokeNonvirtualChar(method, instance, args);
        } else if (method.getReturnType() == double.class) {
            return NativeAccessor.invokeNonvirtualDouble(method, instance, args);
        } else if (method.getReturnType() == float.class) {
            return NativeAccessor.invokeNonvirtualFloat(method, instance, args);
        } else if (method.getReturnType() == int.class) {
            return NativeAccessor.invokeNonvirtualInt(method, instance, args);
        } else if (method.getReturnType() == long.class) {
            return NativeAccessor.invokeNonvirtualLong(method, instance, args);
        } else if (method.getReturnType() == short.class) {
            return NativeAccessor.invokeNonvirtualShort(method, instance, args);
        } else {
            return NativeAccessor.invokeNonvirtualObject(method, instance, args);
        }
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static void callVoid(long method, @Nullable Object instance, Object... args) {
        NativeAccessor.callVoid(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static boolean callBoolean(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callBoolean(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static byte callByte(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callByte(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static char callChar(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callChar(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static double callDouble(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callDouble(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static float callFloat(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callFloat(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static int callInt(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callInt(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static long callLong(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callLong(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static short callShort(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callShort(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}.
     * @param method the method
     * @param instance the instance
     */
    public static Object callObject(long method, @Nullable Object instance, Object... args) {
        return NativeAccessor.callObject(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static void callNonvirtualVoid(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        NativeAccessor.callNonvirtualVoid(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static boolean callNonvirtualBoolean(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualBoolean(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static byte callNonvirtualByte(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualByte(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static char callNonvirtualChar(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualChar(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static double callNonvirtualDouble(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualDouble(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static float callNonvirtualFloat(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualFloat(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static int callNonvirtualInt(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualInt(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static long callNonvirtualLong(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualLong(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static short callNonvirtualShort(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualShort(method, instance, args);
    }

    /**
     * Call a method without calling {@link Method#setAccessible(boolean)}. This method also allows invoking
     * "super super" method.
     * @param method the method
     * @param instance the instance
     */
    public static Object callNonvirtualObject(long method, @NotNull Object instance, Object... args) {
        Objects.requireNonNull(instance);
        return NativeAccessor.callNonvirtualObject(method, instance, args);
    }

    /**
     * Create new instance without calling {@link Constructor#setAccessible(boolean)}.
     * @param constructor the constructor to call
     */
    @NotNull
    public static <T> T newInstance(@NotNull Constructor<T> constructor, Object... args) {
        Objects.requireNonNull(constructor);
        return NativeAccessor.newInstance(constructor, args);
    }

    /**
     * Find a static method with class and matching name + signature.
     * @param clazz class to find field at
     * @param name method name
     * @param signature method signature
     * @return method, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Method getStaticMethod(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        return NativeAccessor.getStaticMethod(clazz, name, signature);
    }

    /**
     * Find an instance method with class and matching name + signature.
     * @param clazz class to find field at
     * @param name method name
     * @param signature method signature
     * @return method, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Method getNonstaticMethod(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        return NativeAccessor.getNonstaticMethod(clazz, name, signature);
    }

    /**
     * Find a method with class and matching name + signature.
     * @param clazz class to find field at
     * @param name method name
     * @param signature method signature
     * @return method, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Method getMethod(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        try {
            return NativeAccessor.getStaticMethod(clazz, name, signature);
        } catch (NoSuchElementException ignore) {
            return NativeAccessor.getNonstaticMethod(clazz, name, signature);
        }
    }

    /**
     * Find a method with class and matching name + signature.
     * @param clazz class to find field at
     * @param name method name
     * @param signature method signature
     * @return method but in optional
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Optional<Method> getMethodOptional(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        try {
            return Optional.of(NativeAccessor.getStaticMethod(clazz, name, signature));
        } catch (NoSuchElementException ignore) {
            try {
                return Optional.of(NativeAccessor.getNonstaticMethod(clazz, name, signature));
            } catch (NoSuchElementException ignore2) {
                return Optional.empty();
            }
        }
    }

    /**
     * Find a static field with class and matching name + signature.
     * @param clazz class to find field at
     * @param name field name
     * @param signature field signature
     * @return field, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Field getStaticField(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        return NativeAccessor.getStaticField(clazz, name, signature);
    }

    /**
     * Find an instance field with class and matching name + signature.
     * @param clazz class to find field at
     * @param name field name
     * @param signature field signature
     * @return field, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Field getNonstaticField(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        return NativeAccessor.getNonstaticField(clazz, name, signature);
    }

    /**
     * Find a field with class and matching name + signature.
     * @param clazz class to find field at
     * @param name field name
     * @param signature field signature
     * @return field, can never be null
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Field getField(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        try {
            return NativeAccessor.getStaticField(clazz, name, signature);
        } catch (NoSuchElementException ignore) {
            return NativeAccessor.getNonstaticField(clazz, name, signature);
        }
    }

    /**
     * Find a field with class and matching name + signature.
     * @param clazz class to find field at
     * @param name field name
     * @param signature field signature
     * @return field but in optional
     * @throws NoSuchElementException if field cannot be found
     */
    @Contract(pure = true)
    @NotNull
    public static Optional<Field> getFieldOptional(@NotNull Class<?> clazz, @NotNull String name, @NotNull String signature) throws NoSuchElementException {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(name);
        Objects.requireNonNull(signature);
        try {
            return Optional.of(NativeAccessor.getStaticField(clazz, name, signature));
        } catch (NoSuchElementException ignore) {
            try {
                return Optional.of(NativeAccessor.getNonstaticField(clazz, name, signature));
            } catch (NoSuchElementException ignore2) {
                return Optional.empty();
            }
        }
    }

    /**
     * Define a new class for a class loader with provided class bytes.
     * @param name class name
     * @param classLoader class loader to load at.
     * @param buf class bytes
     * @param len length of class bytes
     * @return new class
     */
    @NotNull
    public static Class<?> defineClass(@NotNull String name, @NotNull ClassLoader classLoader, byte[] buf, int len) {
        Objects.requireNonNull(name);
        Objects.requireNonNull(classLoader);
        Objects.requireNonNull(buf);
        return NativeAccessor.defineClass(name, classLoader, buf, len);
    }

    /**
     * Triggers force garbage collection. But why?
     */
    public static void forceGarbageCollection() {
        NativeAccessor.forceGarbageCollection();
    }

    /**
     * Get ALL loaded classes.
     * @return all loaded classes
     */
    @NotNull
    public static Class<?>[] getLoadedClasses() {
        return NativeAccessor.getLoadedClasses();
    }

    /**
     * Get all loaded classes in class loader.
     * @param classLoader classLoader to get classes
     * @return all classes in class loader
     */
    @NotNull
    public static Class<?>[] getClassLoaderClasses(@NotNull ClassLoader classLoader) {
        return NativeAccessor.getClassLoaderClasses(classLoader);
    }

    /**
     * Retransform classes
     * @param classes classes to retransform
     */
    public static void retransformClasses(@NotNull Class<?>[] classes) {
        Objects.requireNonNull(classes);
        NativeAccessor.retransformClasses(classes);
    }

    /**
     * Get the object size of an object
     * @param o an object
     * @return object size in bytes
     */
    public static long getObjectSize(@NotNull Object o) {
        Objects.requireNonNull(o);
        return NativeAccessor.getObjectSize(o);
    }

    /**
     * Get the object hashcode of an object
     * @param o an object
     * @return hashcode
     */
    public static int getObjectHashcode(@NotNull Object o) {
        Objects.requireNonNull(o);
        return NativeAccessor.getObjectHashcode(o);
    }

    /**
     * Registers ClassLoadHook for transforming classes.
     */
    public static void registerClassLoadHook(@NotNull ClassLoadHook classLoadHook) {
        Objects.requireNonNull(classLoadHook);
        NativeAccessor.registerClassLoadHook(classLoadHook);
    }

    /**
     * Checks whether the class is modifiable. Primitive classes and array classes are never modifiable.
     * @param clazz the class to check
     * @return true if modifiable, false otherwise
     */
    public static boolean isModifiableClass(@NotNull Class<?> clazz) {
        Objects.requireNonNull(clazz);
        if (clazz.isPrimitive()) return false;
        if (clazz.isArray()) return false;
        return NativeAccessor.isModifiableClass(clazz);
    }

    /**
     * Checks if NativeUtil can redefine some class.
     * @throws NativeException when an error occurred while getting capabilities
     */
    public static boolean canRedefineClasses() throws NativeException {
        return NativeAccessor.canRedefineClasses();
    }

    /**
     * The redefinition may change method bodies, the constant pool and attributes. The redefinition must not add,
     * remove or rename fields or methods, change the signatures of methods, change modifiers, or change inheritance.
     * These restrictions may be lifted in future versions.
     * <p>See <a href="https://docs.oracle.com/javase/8/docs/platform/jvmti/jvmti.html#RedefineClasses">JVM(TM) Tool Interface 1.2.3</a> for more details.</p>
     * @throws NativeException if one or more class definitions cannot be modified, not a valid class, contains
     * unsupported version, fails verification, incorrect name, changed hierarchy or changed modifier. NativeException
     * also will be thrown if method was added during redefinition, method modifier was changed during redefinition,
     * field was added or changed during redefinition, field was added or changed during redefinition, or some unknown
     * error occurs.
     * @throws ClassFormatError if class format is invalid
     * @throws ClassCircularityError if class circularity was detected during redefinition
     */
    public static void redefineClasses(@NotNull ClassDefinition[] classDefinition) throws NativeException, ClassFormatError, ClassCircularityError {
        if (!canRedefineClasses()) throw new RuntimeException("Cannot redefine classes");
        Objects.requireNonNull(classDefinition);
        for (ClassDefinition def : classDefinition) {
            if (!isModifiableClass(def.clazz)) {
                throw new IllegalArgumentException("Class " + def.clazz.getCanonicalName() + " is unmodifiable");
            }
        }
        NativeAccessor.redefineClasses(classDefinition);
    }

    /**
     * Gets the address of the id of the method. <strong>Note: This method allocates the memory and you will need to
     * {@link #free(long) free} the memory.</strong> Thus, it is not wise to call this method in a loop.
     * @param method the method
     * @return the address
     */
    public static long getMethodId(@NotNull Method method) {
        Objects.requireNonNull(method);
        return NativeAccessor.getMethodId(method);
    }

    /**
     * Gets the reflected method from the id. Passing the wrong address may cause a JVM crash.
     * @param method the method address
     * @param isStatic true if the method is static, false otherwise
     * @return the reflected method
     */
    public static Method getMethodFromId(long method, boolean isStatic) {
        return NativeAccessor.getMethodFromId(method, isStatic);
    }

    /**
     * Attempt to free memory at the given address. This method may cause the JVM to crash when an invalid address is
     * passed to the method.
     * @param address the address
     */
    public static void free(long address) {
        NativeAccessor.free(address);
    }

    /**
     * Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an
     * unsigned char). This method is not guaranteed to succeed and may crash the JVM when an invalid address is
     * passed to the method.
     * @param address Pointer to the block of memory to fill.
     * @param value Value to be set. The value is passed as an int, but the function fills the block with memory using
     *              the unsigned char conversion of this value.
     * @param size Number of bytes to be set to the value.
     * @return ptr
     */
    public static long memset(long address, int value, int size) {
        return NativeAccessor.memset(address, value, size);
    }

    /**
     * Sets the CPU affinity of the specified thread. This method only works on Linux.
     * @param threadId the thread id
     * @param cpuId the cpu id
     */
    public static void setAffinity(int threadId, int cpuId) {
        NativeAccessor.setAffinity(threadId, cpuId);
    }
}
