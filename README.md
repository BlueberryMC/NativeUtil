# NativeUtil

[![](https://img.shields.io/maven-central/v/net.blueberrymc/native-util)](https://central.sonatype.com/artifact/net.blueberrymc/native-util)

Provides some methods that are possible in JNI, but not possible in Java (without using Unsafe etc.)

## Note
- `callTypeMethod` and `invokeType` methods are 30x+ slower than reflection (68.447 ± 30.569 ns/op)
- Method with `java.lang.Void` parameter type is not supported and will crash the JVM when trying to invoke them
- You need to use `BoxedValue` class to pass the value of boxed primitive type to method, for example: https://github.com/BlueberryMC/NativeUtil/blob/c194dd4f61f7f147fc5f49944db00f537b68d867/src/test/java/net/blueberrymc/nativeutil/NativeUtilTest.java#L40-L43

## Repository

### Maven

```xml
<repositories>
    ...
    <repository>
        <id>blueberrymc-repo</id>
        <url>https://repo.blueberrymc.net/repository/maven-public/</url>
    </repository>
</repositories>
<dependencies>
    <dependency>
        <groupId>net.blueberrymc</groupId>
        <artifactId>native-util</artifactId>
        <version>[version]</version>
    </dependency>
</dependencies>
```

### Gradle

```groovy
repositories {
    maven {
        url "https://repo.blueberrymc.net/repository/maven-public/"
    }
}

dependencies {
    implementation 'net.blueberrymc:native-util:[version]'
}
```

### Gradle (Kotlin)

```kotlin
repositories {
    maven { url = uri("https://repo.blueberrymc.net/repository/maven-public/") }
}

dependencies {
    implementation("net.blueberrymc:native-util:[version]")
}
```
