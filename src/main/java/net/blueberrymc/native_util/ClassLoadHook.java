package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.security.ProtectionDomain;

public interface ClassLoadHook {
    byte@Nullable[] transform(@Nullable ClassLoader loader,
                              @NotNull String className,
                              @Nullable Class<?> classBeingRedefined,
                              @NotNull ProtectionDomain protectionDomain,
                              byte[] buf);
}
