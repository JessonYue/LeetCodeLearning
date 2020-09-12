cmake_minimum_required(VERSION 3.16)
project(cpp_study)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32)

add_executable(cpp_study dns/dns.cpp dns/dns.h dns/dns_test.cpp)



