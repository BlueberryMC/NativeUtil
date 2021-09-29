package net.blueberrymc.native_util;

import javassist.ClassPool;
import javassist.CtClass;
import org.junit.Test;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.NoSuchElementException;

public class NativeUtilTest {
    @Test
    public void allocateInstance() {
        YouCannotCreateInstanceOfThisClass instance = NativeUtil.allocateInstance(YouCannotCreateInstanceOfThisClass.class);
        assert instance.get42() == 42;
    }

    @Test
    public void setAndGet() throws ReflectiveOperationException {
        Field field = YouCannotCreateInstanceOfThisClass.class.getDeclaredField("i_hope_i_am_not_editable");
        NativeUtil.set(field, null, "edited");
        String s = (String) NativeUtil.get(field, null);
        assert s.equals("edited") : s;

        Field iField = YouCannotCreateInstanceOfThisClass.class.getDeclaredField("i");
        NativeUtil.set(iField, null, 4);
        int i = NativeUtil.getInt(iField, null);
        assert i == 4 : i;
    }

    @Test
    public void invoke() throws ReflectiveOperationException {
        YouCannotCreateInstanceOfThisClass instance = NativeUtil.allocateInstance(YouCannotCreateInstanceOfThisClass.class);
        Method method = YouCannotCreateInstanceOfThisClass.class.getDeclaredMethod("calculate", int.class, int.class);
        int i = (int) NativeUtil.invoke(method, instance, 100000, 14514);
        assert i == 114514 : i;
        Method method2 = YouCannotCreateInstanceOfThisClass.class.getDeclaredMethod("calculate", Integer.class, Integer.class);
        int i2 = (int) NativeUtil.invoke(method2, null, 100000, 15115);
        assert i2 == 115115 : i2;
    }

    @Test
    public void newInstance() throws ReflectiveOperationException {
        YouCannotCreateInstanceOfThisClass instance = NativeUtil.newInstance(YouCannotCreateInstanceOfThisClass.class.getDeclaredConstructor(Void.class), (Object) null);
        assert instance.calculate(1, 1) == 2;
    }

    @Test(expected = NoSuchElementException.class)
    public void testNoSuchStaticMethod() {
        NativeUtil.getMethod(NoSuchElementException.class, "blabla", "blabla").getClass().getClassLoader();
        assert false;
    }

    @Test
    public void testGetStaticMethod() {
        Method m = NativeUtil.getMethod(YouCannotCreateInstanceOfThisClass.class, "calculate", "(Ljava/lang/Integer;Ljava/lang/Integer;)I");
        int i = (int) NativeUtil.invoke(m, null, 44, -2);
        assert i == 42 : i;
    }

    @Test
    public void testGetNonstaticMethod() {
        Method m = NativeUtil.getMethod(YouCannotCreateInstanceOfThisClass.class, "get42", "()I");
        assert m.getReturnType() == int.class;
    }

    @Test
    public void testInvokeNonvirtual() {
        B b = NativeUtil.allocateInstance(B.class);
        Method m = NativeUtil.getMethod(A.class, "getSomething", "()I");
        int i = NativeUtil.invokeNonvirtualInt(m, b);
        assert i == 42 : i;
        assert b.getSomething() == -1;
    }

    @Test
    public void testInvokeNonvirtualOnInterface() {
        TestInterface ti = () -> 1;
        int i = NativeUtil.invokeNonvirtualInt(NativeUtil.getMethod(TestInterface.class, "defaultMethod", "(I)I"), ti, 1);
        assert i == 125 : i;
        int ix = NativeUtil.invokeNonvirtualInt(NativeUtil.getMethod(TestInterface.class, "defaultMethod", "()I"), ti);
        assert ix == 123 : ix;
        TestInterface fakeTi = (TestInterface) Proxy.newProxyInstance(
                NativeUtilTest.class.getClassLoader(),
                new Class[] { TestInterface.class },
                (proxy, method, args) -> {
                    if (method.isDefault()) {
                        return NativeUtil.invokeNonvirtual(method, proxy, args);
                    }
                    return 1;
                });
        int iy = NativeUtil.invokeNonvirtualInt(NativeUtil.getMethod(TestInterface.class, "defaultMethod", "(I)I"), fakeTi, 0);
        assert iy == 124 : iy;
    }

    @Test
    public void testGetLoadedClasses() {
        assert NativeUtil.getLoadedClasses().length >= 1;
    }

    @Test
    public void testGetObjectSize() {
        long size = NativeUtil.getObjectSize(new Object());
        assert size == 16L : size;
    }

    @Test
    public void testRedefineClass() throws Exception {
        CtClass clazz = ClassPool.getDefault().get("net.blueberrymc.native_util.NativeUtilTest$C");
        clazz.getMethod("getsomething", "()I").setBody("return 22222;");
        clazz.getMethod("getSomething", "()I").setBody("return 23456;");
        ClassDefinition[] definitions = new ClassDefinition[]{ new ClassDefinition(C.class, clazz.toBytecode()) };
        C c = new C();
        assert C.getsomething() == 11111;
        assert c.getSomething() == 12345;
        NativeUtil.redefineClasses(definitions);
        assert C.getsomething() == 22222;
        //noinspection ConstantConditions
        assert c.getSomething() == 23456;
    }

    // test data

    private interface TestInterface {
        default int defaultMethod(int i) {
            return 123 + i + method();
        }

        default int defaultMethod() {
            return 123;
        }

        int method();
    }

    private static class A {
        @SuppressWarnings("unused")
        public int getSomething() {
            return 42;
        }
    }

    private static class B extends A {
        public int getSomething() {
            return -1;
        }
    }

    private static class C {
        public static int getsomething() {
            return 11111;
        }

        public int getSomething() {
            return 12345;
        }
    }

    @SuppressWarnings("unused")
    private static class YouCannotCreateInstanceOfThisClass {
        private static final String i_hope_i_am_not_editable = "unedited";
        private static final int i = 0;

        private YouCannotCreateInstanceOfThisClass() {
            throw new AssertionError();
        }

        private YouCannotCreateInstanceOfThisClass(@SuppressWarnings("unused") Void unused) {}

        public int get42() {
            return 42;
        }

        public Integer calculate(int x, int y) {
            return x + y;
        }

        private static int calculate(Integer x, Integer y) {
            return x + y;
        }
    }
}
