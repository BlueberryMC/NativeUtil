package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;

import java.util.Objects;
import java.util.jar.JarFile;

public class NativeUtil {
    /**
     * Adds an url to bootstrap class loader.
     * @param url an url to add
     * @see java.lang.instrument.Instrumentation#appendToBootstrapClassLoaderSearch(JarFile)
     */
    public static void appendToBootstrapClassLoaderSearch(@NotNull String url) {
        Objects.requireNonNull(url);
        NativeAccessor.appendToBootstrapClassLoaderSearch(url);
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
}
