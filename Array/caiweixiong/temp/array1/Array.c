//
// Created by Vashon on 2020/7/21.
//

#include "Array.h"

// 通过数组的容量字段进行动态的分配空间
static void allocMemoryByCapacity(Array *array) {
    int capacity = array->capacity;
    if (array->length >= capacity) {    // 容量已满，动态扩容
        capacity += (capacity >> 1);
        Object **objects = realloc(array->objects, capacity * sizeof(Object *));
        assert(objects != NULL);
        array->capacity = capacity;
        array->objects = objects;
        printf("Array alloc memory, capacity is : %d\n", capacity);
    }
}

Array *newArray() {
    Array *array = malloc(sizeof(Array));
    assert(array != NULL);
    array->capacity = DEFAULT_CAPACITY;
    array->length = 0;
    array->objects = malloc(array->capacity * sizeof(Object *));
    assert(array->objects != NULL);
    return array;
}

int getArrayLength(Array *array) {
    return array->length;
}

// 引用对象，增加对象的引用计数
static void retainObject(Array *array, int index, Object *object) {
    OBJ_RETAIN(object);
    array->objects[index] = object;
    array->length++;
}

void addElement(Array *array, Object *object) {
    allocMemoryByCapacity(array);
    retainObject(array, array->length, object);
}

void addAll(Array *destArray, Array *srcArray) {
    for (int i = 0; i < srcArray->length; ++i)
        addElement(destArray, srcArray->objects[i]);
}

void insertElement(Array *array, Object *object, int index) {
    int length = array->length;
    assert(index <= length);
    allocMemoryByCapacity(array);
    for (int i = length; i > index; array->objects[i] = array->objects[i - 1], --i);    // 将插入位置及之后的元素全部后移
    retainObject(array, index, object);
}

Object *getElement(Array *array, int index) {
    assert(index < array->length);
    return array->objects[index];
}

// 回收对象，减少对象的引用计数并回调
static void releaseObject(Array *array, int index, void (*callback)(Object *)) {
    Object *object = getElement(array, index);
    OBJ_RELEASE(object);    // 减少对象的引用计数
    callback(object);       // 将对象回调到外面，做资源释放等操作
}

void removeElement(Array *array, int index, void (*callback)(Object *)) {
    releaseObject(array, index, callback);
    int length = --array->length;   // 数组长度减少
    for (int i = index; i < length; array->objects[i] = array->objects[i + 1], ++i);    // 移动数组中其他的元素到指定的位置
}

void removeAll(Array *array, void (*callback)(Object *)) {
    for (int i = 0; i < array->length; ++i)
        releaseObject(array, i, callback);
    array->length = 0;      // 记得将数组的长度初始化
}

void printArray(Array *array, void (*callback)(Object *)) {
    for (int i = 0; i < array->length; ++i)
        callback(getElement(array, i)); // 迭代数组，将数组每个对象回调到外面，具体外面再做对应的操作
}

void destroyArray(Array *array) {
    free(array->objects);
    free(array);
}