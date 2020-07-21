//
// Created by Vashon on 2020/7/21.
//

#include "Array.h"

// 通过数组的容量字段进行动态的分配空间
static Object **allocMemoryByCapacity(Array *array) {
    Object **objects = realloc(array->objects, array->capacity * sizeof(Object *));
    assert(objects != NULL);
    return objects;
}

Array *newArray() {
    Array *array = malloc(sizeof(Array));
    assert(array != NULL);
    array->capacity = DEFAULT_CAPACITY;
    array->length = 0;
    array->objects = NULL;   // 这一句必须写，初始化指针域
    array->objects = allocMemoryByCapacity(array);
    return array;
}

int getArrayLength(Array *array) {
    return array->length;
}

void addElement(Array *array, Object *object) {
    int capacity = array->capacity;
    int length = array->length;
    if (length >= capacity) {    // 容量已满，动态扩容
        capacity += (capacity >> 1);
        array->capacity = capacity;
        array->objects = allocMemoryByCapacity(array);
    }
    OBJ_RETAIN(object);
    array->objects[length] = object;
    array->length++;
}

void addAll(Array *destArray, Array *srcArray) {
    for (int i = 0; i < srcArray->length; ++i) {
        addElement(destArray, srcArray->objects[i]);
    }
}

void insertElement(Array *array, Object *object, int index) {
    int capacity = array->capacity;
    int length = array->length;
    assert(index <= length);
    if (length >= capacity) {    // 容量已满，动态扩容
        capacity += (capacity >> 1);
        array->capacity = capacity;
        array->objects = allocMemoryByCapacity(array);
    }
    for (int i = length; i > index; array->objects[i] = array->objects[i - 1], --i);
    OBJ_RETAIN(object);
    array->objects[index] = object;
    array->length++;
}

Object *getElement(Array *array, int index) {
    int length = array->length;
    assert(index < length);
    return array->objects[index];
}

void removeElement(Array *array, int index, void (* callback)(Object *)) {
    Object *object = getElement(array, index);
    OBJ_RELEASE(object);
    callback(object);
}

void removeAll(Array *array, void (* callback)(Object *)) {
    for (int i = 0; i < array->length; ++i) {
        removeElement(array, i, callback);
    }
}

void printArray(Array *array, void (* callback)(Object *)) {
    for (int i = 0; i < array->length; ++i) {
        callback(getElement(array, i));
    }
}

void destroyArray(Array *array) {
    free(array->objects);
    free(array);
}