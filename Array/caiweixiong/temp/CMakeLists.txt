cmake_minimum_required(VERSION 3.16)
project(basedatastruct C)

set(CMAKE_C_STANDARD 11)

add_executable(basedatastruct main.c
#        array/JavaObject.h array/JavaObject.c array/Integer.c array/Integer.h array/String.c array/String.h array/Person.c array/Person.h array/Array.c array/Array.h
        array1/Object.c array1/Object.h array1/Integer.c array1/Integer.h array1/String.c array1/String.h array1/Person.c array1/Person.h array1/Array.c array1/Array.h)