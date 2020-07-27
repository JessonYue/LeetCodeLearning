cmake_minimum_required(VERSION 3.16)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)
## LeetCode 1
add_executable(Cpp_L1 Base/datastruct.h L1/solution.c)

add_executable(Cpp main.cpp)
add_executable(Cpp_L451 L451/Solution.cpp)
add_executable(Cpp_L101 L101/SolutionC.c)
add_executable(Cpp_L3 L3/solution.c)
