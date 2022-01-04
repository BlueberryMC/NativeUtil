# NativeUtil
Adds some methods that is possible in JNI, but not possible in Java (without using Unsafe etc).

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
        <version>1.2.6</version>
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
    implementation 'net.blueberrymc:native-util:1.2.6'
}
```

### Gradle (Kotlin)

```kotlin
repositories {
    maven { url = uri("https://repo.blueberrymc.net/repository/maven-public/") }
}

dependencies {
    implementation("net.blueberrymc:native-util:1.2.6")
}
```
