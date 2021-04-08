package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;

import java.util.Objects;

public class NativeUtil {
    public static void appendToBootstrapClassLoaderSearch(@NotNull String url) {
        Objects.requireNonNull(url);
        NativeAccessor.appendToBootstrapClassLoaderSearch(url);
    }

    public static void appendToSystemClassLoaderSearch(@NotNull String url) {
        Objects.requireNonNull(url);
        NativeAccessor.appendToSystemClassLoaderSearch(url);
    }
}
