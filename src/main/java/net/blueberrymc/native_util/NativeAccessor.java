package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;

public class NativeAccessor {
    static {
        NativeCode.loadLibrary("libnativeutil");
    }

    public static native void appendToBootstrapClassLoaderSearch(@NotNull String url);
    public static native void appendToSystemClassLoaderSearch(@NotNull String url);
    public static native <T> T allocateInstance(@NotNull Class<T> clazz);
}
