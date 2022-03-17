package net.blueberrymc.native_util;

import org.jetbrains.annotations.NotNull;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URISyntaxException;

public class NativeCode {
    private boolean loaded = false;
    private final String name;
    private String suffix = ".so";

    public NativeCode(@NotNull String name) {
        LazyOSType os = LazyOSType.detectOS();
        if (os == LazyOSType.Windows) suffix = ".dll";
        if (os == LazyOSType.Mac_OS || os == LazyOSType.Mac_OS_X) suffix = ".dylib";
        this.name = name;
    }

    public boolean load() throws UnsatisfiedLinkError {
        if (loaded) return true;
        String fullName = name + suffix;
        try {
            System.loadLibrary(fullName);
            loaded = true;
            return true;
        } catch (Throwable ignore) {}
        try (InputStream soFile = NativeCode.class.getClassLoader().getResourceAsStream(fullName)) {
            if (soFile == null) {
                throw new RuntimeException(
                        new FileNotFoundException(
                                "Could not find " + fullName + " in jar file\n" +
                                        "Full path: " + NativeCode.class.getProtectionDomain().getCodeSource().getLocation().toURI().getPath()
                        )
                );
            }
            File temp = File.createTempFile(name, suffix);
            temp.deleteOnExit();
            OutputStream os = new FileOutputStream(temp);
            Bytes.copy(soFile, os);
            os.close();
            System.load(temp.getPath());
            loaded = true;
        } catch (IOException | URISyntaxException ignore) {}
        return loaded;
    }

    public static boolean loadLibrary(@NotNull String name) throws UnsatisfiedLinkError {
        return new NativeCode(name).load();
    }
}
