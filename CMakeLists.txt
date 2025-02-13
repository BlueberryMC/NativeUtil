# Make sure to specify x64 toolchain

cmake_minimum_required(VERSION 3.12)
project(nativeutil LANGUAGES CXX)
set(JAVA_AWT_LIBRARY "")
set(JAVA_AWT_INCLUDE_PATH "")
find_package(JNI)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(nativeutil PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(nativeutil "${CMAKE_THREAD_LIBS_INIT}")
endif()

include_directories(.)
if (JNI_FOUND)
    include_directories("${JNI_INCLUDE_DIRS}")
else()
    include_directories("$ENV{JAVA_HOME}/include;$ENV{JAVA_HOME}/include/win32;$ENV{JAVA_HOME}/include/linux;$ENV{JAVA_HOME}/include/darwin")
endif()

add_library(nativeutil SHARED
        src/main/c/native_util.cpp
        src/main/c/native_util.h
        src/main/c/common_tools.cpp)

set_target_properties(nativeutil PROPERTIES CXX_STANDARD 14)
