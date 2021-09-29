package net.blueberrymc.native_util;

import java.util.Objects;

public class ClassDefinition {
    public final Class<?> clazz;
    public final byte[] bytes;

    public ClassDefinition(Class<?> clazz, byte[] bytes) {
        Objects.requireNonNull(clazz);
        Objects.requireNonNull(bytes);
        this.clazz = clazz;
        this.bytes = bytes;
    }
}
