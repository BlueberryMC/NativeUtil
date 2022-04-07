package net.blueberrymc.nativeutil;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.security.ProtectionDomain;

public interface ClassLoadHook {
    byte@Nullable[] transform(@Nullable ClassLoader loader,
                              @NotNull String className,
                              @Nullable Class<?> classBeingRedefined,
                              @Nullable ProtectionDomain protectionDomain,
                              byte[] buf);
}
