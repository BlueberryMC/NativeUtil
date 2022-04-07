# NativeUtil
Adds some methods that are possible in JNI, but not possible in Java (without using Unsafe etc.)

Be careful though: `callTypeMethod` and `invokeType` methods are ~34x slower than reflection (68.447 ± 30.569 ns/op).

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
