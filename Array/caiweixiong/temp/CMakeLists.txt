cmake_minimum_required(VERSION 3.16)
project(basedatastruct C)

set(CMAKE_C_STANDARD 11)

add_executable(basedatastruct main.c array/JavaObject.h array/JavaObject.c array/Integer.c array/Integer.h array/String.c array/String.h array/Person.c array/Person.h array/Array.c array/Array.h)