//
// Created by Vashon on 2020/7/20.
//

#include <stdlib.h>
#include <assert.h>
#include "Array.h"

// 分配空间
static Object *allocMemoryByCapacity(Array *array) {
    Object *value = realloc(array->value, sizeof(Object) * array->capacity);
    assert(value != NULL);
    return value;
}

Array *newArray() {
    Array *array = malloc(sizeof(Array));
    assert(array != NULL);
    array->length = 0;
    array->capacity = DEFAULT_CAPACITY;
    array->value = NULL;    // 这一句必须写！
    array->value = allocMemoryByCapacity(array);
    return array;
}

void addElement(Array *array, Object object) {
    int length = array->length;
    int oldCapacity = array->capacity;
    // 数组的长度比容量大，进行动态扩容，扩容比例为原本的 1.5 倍
    if (length >= oldCapacity) {
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        array->capacity = newCapacity;
        array->value = allocMemoryByCapacity(array);
    }
    OBJ_RETAIN(object);
    array->value[length] = object;
    array->length++;
}

Array *removeIndexAt(Array *array, int index) {
    int length = array->length;
    assert(index >= 0 && index < length);
    OBJ_RELEASE(array->value[index]);
    length = --array->length;
    for (int i = index; i < length; array->value[i] = array->value[i + 1], ++i);
    return array;
}

Array *insertIndexAt(Array *array, Object object, int index) {
    int length = array->length;
    int oldCapacity = array->capacity;
    if (length >= oldCapacity) {
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        array->capacity = newCapacity;
        array->value = allocMemoryByCapacity(array);
    }
    OBJ_RETAIN(object);
    length = ++array->length;
    for (int i = length - 1; i > index; array->value[i] = array->value[i - 1], --i);
    array->value[index] = object;
    return array;
}

Object getObjectIndexAt(Array *array, int index) {
    assert(index >= 0 && index < array->length);
    return array->value[index];
}

int getArrayLength(Array *array) {
    return array->length;
}

void destroyArray(Array *array) {
    free(array->value);
    free(array);
}