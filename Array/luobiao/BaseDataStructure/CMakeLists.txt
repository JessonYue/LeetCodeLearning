cmake_minimum_required(VERSION 3.16)
project(BaseDataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinkedList LinkedList.cpp LinkedList.h)
add_executable(Stack Stack.cpp Stack.h)
add_executable(PriorityQueue PriorityQueue.c)
add_executable(queue queue.c)
add_executable(ringbuffer ringbuffer.c)
add_executable(BinaryTree BinaryTree.cpp Test.c )
add_executable(BST BST.cpp)
add_executable(Hash Hash.c)
add_executable(LinkedListHash LinkedListHash.cpp LinkedListHash.h)
add_executable(ELFParse ELFParse.cpp ELFParse.h)

#ELF.cpp


