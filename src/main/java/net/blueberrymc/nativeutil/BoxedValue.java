package net.blueberrymc.nativeutil;

public class BoxedValue {
    @SuppressWarnings({ "FieldCanBeLocal", "unused" })
    private final Object value; // used in native code

    public BoxedValue(Object value) {
        this.value = value;
    }
}
