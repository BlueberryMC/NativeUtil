package net.blueberrymc.nativeutil;

import org.junit.Test;

public class InvokeTest {
    @Test
    public void testInvokeVoid() throws Exception {
        NativeUtil.invoke(InvokeTest.class.getMethod("_testVoid"), this);
        NativeUtil.invokeNonvirtual(InvokeTest.class.getMethod("_testVoid"), this);
    }

    @Test
    public void testInvokeBoolean() throws Exception {
        boolean z = (boolean) NativeUtil.invoke(InvokeTest.class.getMethod("testBoolean", boolean.class), this, true);
        assert z : "testBoolean returned false";
    }

    @Test
    public void testInvokeByte() throws Exception {
        byte b = (byte) NativeUtil.invoke(InvokeTest.class.getMethod("testByte", byte.class), this, (byte) 122);
        assert b == 122 : "testByte returned " + b;
    }

    @Test
    public void testInvokeChar() throws Exception {
        char c = (char) NativeUtil.invoke(InvokeTest.class.getMethod("testChar", char.class), this, '6');
        assert c == '6' : "testChar returned " + c;
    }

    @Test
    public void testInvokeDouble() throws Exception {
        double d = (double) NativeUtil.invoke(InvokeTest.class.getMethod("testDouble", double.class), this, 0.1 + 0.2);
        assert d == 0.1 + 0.2 : "testDouble returned " + d;
    }

    @Test
    public void testInvokeFloat() throws Exception {
        float f = (float) NativeUtil.invoke(InvokeTest.class.getMethod("testFloat", float.class), this, 0.1f + 0.2f);
        assert f == 0.1f + 0.2f : "testFloat returned " + f;
    }

    @Test
    public void testInvokeInt() throws Exception {
        int i = (int) NativeUtil.invoke(InvokeTest.class.getMethod("testInt", int.class), this, 999);
        assert i == 999 : "testInt returned " + i;
    }

    @Test
    public void testInvokeLong() throws Exception {
        long j = (long) NativeUtil.invoke(InvokeTest.class.getMethod("testLong", long.class), this, 123456789012345L);
        assert j == 123456789012345L : "testLong returned " + j;
    }

    @Test
    public void testInvokeShort() throws Exception {
        short s = (short) NativeUtil.invoke(InvokeTest.class.getMethod("testShort", short.class), this, (short) 123);
        assert s == 123 : "testShort returned " + s;
    }

    @Test
    public void testInvokeObject() throws Exception {
        Object o = new Object[] { "Hello", "World" };
        Object obj = NativeUtil.invoke(InvokeTest.class.getMethod("testObject", Object.class), this, o);
        assert obj == o : "testObject returned " + obj;
    }

    @Test
    public void testCallVoid() throws Exception {
        // example of invoking callVoid/callNonvirtualVoid and freeing the memory
        long address = NativeUtil.getMethodId(InvokeTest.class.getMethod("_testVoid"));
        NativeUtil.callVoid(address, this);
        NativeUtil.callNonvirtualVoid(address, this);
        NativeUtil.free(address);
    }

    @Test
    public void testCallBoolean() throws Exception {
        boolean z = NativeUtil.callBoolean(NativeUtil.getMethodId(InvokeTest.class.getMethod("testBoolean", boolean.class)), this, true);
        assert z : "testBoolean returned false";
    }

    @Test
    public void testCallByte() throws Exception {
        byte b = NativeUtil.callByte(NativeUtil.getMethodId(InvokeTest.class.getMethod("testByte", byte.class)), this, (byte) 122);
        assert b == 122 : "testByte returned " + b;
    }

    @Test
    public void testCallChar() throws Exception {
        char c = NativeUtil.callChar(NativeUtil.getMethodId(InvokeTest.class.getMethod("testChar", char.class)), this, '6');
        assert c == '6' : "testChar returned " + c;
    }

    @Test
    public void testCallDouble() throws Exception {
        double d = NativeUtil.callDouble(NativeUtil.getMethodId(InvokeTest.class.getMethod("testDouble", double.class)), this, 0.1 + 0.2);
        assert d == 0.1 + 0.2 : "testDouble returned " + d;
    }

    @Test
    public void testCallFloat() throws Exception {
        float f = NativeUtil.callFloat(NativeUtil.getMethodId(InvokeTest.class.getMethod("testFloat", float.class)), this, 0.1f + 0.2f);
        assert f == 0.1f + 0.2f : "testFloat returned " + f;
    }

    @Test
    public void testCallInt() throws Exception {
        int i = NativeUtil.callInt(NativeUtil.getMethodId(InvokeTest.class.getMethod("testInt", int.class)), this, 999);
        assert i == 999 : "testInt returned " + i;
    }

    @Test
    public void testCallLong() throws Exception {
        long j = NativeUtil.callLong(NativeUtil.getMethodId(InvokeTest.class.getMethod("testLong", long.class)), this, 123456789012345L);
        assert j == 123456789012345L : "testLong returned " + j;
    }

    @Test
    public void testCallShort() throws Exception {
        short s = NativeUtil.callShort(NativeUtil.getMethodId(InvokeTest.class.getMethod("testShort", short.class)), this, (short) 123);
        assert s == 123 : "testShort returned " + s;
    }

    @Test
    public void testCallObject() throws Exception {
        Object o = new Object[] { "Hello", "World" };
        Object obj = NativeUtil.callObject(NativeUtil.getMethodId(InvokeTest.class.getMethod("testObject", Object.class)), this, o);
        assert obj == o : "testObject returned " + obj;
    }

    public void _testVoid() {
    }

    public boolean testBoolean(boolean z) {
        return z;
    }

    public byte testByte(byte b) {
        return b;
    }

    public char testChar(char c) {
        return c;
    }

    public double testDouble(double d) {
        return d;
    }

    public float testFloat(float f) {
        return f;
    }

    public int testInt(int i) {
        return i;
    }

    public long testLong(long j) {
        return j;
    }

    public short testShort(short s) {
        return s;
    }

    public Object testObject(Object o) {
        return o;
    }
}
