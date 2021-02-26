cmake_minimum_required(VERSION 3.10)
project(BaseDataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinkedList list/LinkedList.cpp list/LinkedList.h)
add_executable(DoublyLinkedList list/DoublyLinkedList.h list/DoublyLinkedList.cpp)
add_executable(DoublyCircularList list/DoublyCircularList.cpp list/DoublyCircularList.h)
add_executable(Stack stack/Stack.cpp stack/Stack.h)
add_executable(PriorityQueue queue/PriorityQueue.c queue/QueueByList.cpp)
add_executable(queue queue/queue.c)
add_executable(ringbuffer queue/ringbuffer.c)
add_executable(QueueByList queue/QueueByList.cpp)
add_executable(BinaryStack stack/BinaryStack.cpp)
add_executable(BinaryTree BinaryTree.cpp)
add_executable(BST BST.cpp)
add_executable(Hash Hash/Hash.c)
add_executable(HashCPP Hash/Hash.cpp)
add_executable(LinkedListHash LinkedListHash.cpp LinkedListHash.h)
add_executable(HeapSort HeapSort.cpp)
add_executable(Test Test.c)
add_executable(BinarySearch BinarySearch.cpp)
add_executable(Timer Timer.cpp Timer.h)
add_executable(array array/JavaObject.cpp array/JavaObject.h array/String.cpp array/String.h array/Integer.cpp array/Integer.h array/People.cpp array/People.h array/Array.cpp array/Array.h)

add_executable(binarylinkedlist tree/binarylinkedlist.cpp)
add_executable(leveltraversal tree/leveltraversal.cpp)


add_executable(elf elf/elf.h elf/dataType.h elf/soparse.c)

add_executable(float TestFloat.c)
#ELF.cpp


