# Make sure to specify x64 toolchain

cmake_minimum_required(VERSION 3.12)
project(nativeutil LANGUAGES CXX)
set(JAVA_AWT_LIBRARY "")
set(JAVA_AWT_INCLUDE_PATH "")
find_package(JNI)

include_directories(.)
if (JNI_FOUND)
    include_directories("${JNI_INCLUDE_DIRS}")
else()
    include_directories("$ENV{JAVA_HOME}/include;$ENV{JAVA_HOME}/include/win32;$ENV{JAVA_HOME}/include/linux;$ENV{JAVA_HOME}/include/darwin")
endif()

add_library(nativeutil SHARED
        src/main/c/net_blueberrymc_native_util_NativeAccessor.cpp
        src/main/c/net_blueberrymc_native_util_NativeAccessor.h
        src/main/c/common-tools.cpp)

set_target_properties(nativeutil PROPERTIES CXX_STANDARD 14)
