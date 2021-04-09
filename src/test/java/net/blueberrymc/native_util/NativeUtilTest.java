package net.blueberrymc.native_util;

import org.junit.Test;

public class NativeUtilTest {
    @Test
    public void allocateInstance() {
        System system = NativeUtil.allocateInstance(System.class);
        System.out.println("System: " + system);
        assert system != null;
    }
}
