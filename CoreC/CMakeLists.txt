cmake_minimum_required(VERSION 3.10)
project(CoreC)

set(CMAKE_CXX_STANDARD 14)

add_executable(pointer pointer.cpp)

add_executable(address address.cpp)

add_executable(memallocate memallocate.cpp)
#IPC
add_executable(semaphore IPC/semaphore.cpp IPC/semaphore.h)
add_executable(forkpipe IPC/pipe/forkpipe.cpp)
add_executable(sem IPC/pipe/sem.cpp)
#add_executable(systemV IPC/pipe/systemV.cpp)
add_executable(sig IPC/pipe/sig.cpp)

add_executable(MessageQueueSend MessageQueue_Send.cpp)
add_executable(MessageQueueReceive MessageQueue_Receive.cpp)
add_executable(ProcessSched ProcessSched.cpp)



find_package(Threads REQUIRED)
target_link_libraries(sem Threads::Threads)
