package net.blueberrymc.native_util;

public class Benchmark {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 50000; i++) {
            NativeUtil.getObjectSize(new Object());
        }
        long end = System.currentTimeMillis();
        System.out.println("getObjectSize (50000) took " + (end - start) + "ms");
    }
}
