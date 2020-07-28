cmake_minimum_required(VERSION 3.10)
project(BaseDataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinkedList LinkedList.cpp LinkedList.h)
add_executable(Stack Stack.cpp Stack.h)
add_executable(PriorityQueue PriorityQueue.c)
add_executable(queue queue.c)
add_executable(ringbuffer ringbuffer.c)
add_executable(BinaryTree BinaryTree.cpp)
add_executable(BST BST.cpp)
add_executable(Hash Hash.c)
add_executable(LinkedListHash LinkedListHash.cpp LinkedListHash.h)
add_executable(HeapSort HeapSort.cpp)
add_executable(Test Test.c)
add_executable(BinarySearch BinarySearch.cpp)
add_executable(array array/JavaObject.cpp array/JavaObject.h array/String.cpp array/String.h array/Integer.cpp array/Integer.h array/People.cpp array/People.h array/Array.cpp array/Array.h)


#ELF.cpp


