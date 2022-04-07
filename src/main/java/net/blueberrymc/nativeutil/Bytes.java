package net.blueberrymc.nativeutil;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * An utility class to perform I/O operations such as copying InputStream to OutputStream.
 */
class Bytes {
    @Contract
    static long copy(@NotNull InputStream from, @NotNull OutputStream to) throws IOException {
        byte[] buf = new byte[8192];
        long total = 0;
        while (true) {
            int r = from.read(buf);
            if (r == -1) {
                break;
            }
            to.write(buf, 0, r);
            total += r;
        }
        return total;
    }
}
