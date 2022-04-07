package net.blueberrymc.nativeutil;

import org.jetbrains.annotations.NotNull;

enum LazyOSType {
    Linux,
    Mac_OS,
    Mac_OS_X,
    Windows,
    Unknown,
    ;

    @NotNull
    static LazyOSType detectOS() {
        String os = System.getProperty("os.name");
        if (os == null) return Unknown;
        if (os.equals("Linux")) return Linux;
        if (os.equals("Mac OS")) return Mac_OS;
        if (os.equals("Mac OS X")) return Mac_OS;
        if (os.contains("Windows")) return Windows;
        if (os.equals("Solaris")) return Linux;
        if (os.equals("FreeBSD")) return Linux;
        return Unknown;
    }
}
