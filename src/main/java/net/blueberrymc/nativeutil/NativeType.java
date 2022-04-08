package net.blueberrymc.nativeutil;

import org.jetbrains.annotations.NotNull;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * This annotation is used to mark a native type. This is not used anywhere in the NativeUtil.
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target({ ElementType.METHOD, ElementType.PARAMETER })
public @interface NativeType {
    /**
     * The type of the native type.
     * @return type name
     */
    @NotNull
    String value();
}
