//
// Created by Vashon on 2020/7/20.
//

#ifndef BASEDATASTRUCT_ARRAY_H
#define BASEDATASTRUCT_ARRAY_H

#include "JavaObject.h"

#define DEFAULT_CAPACITY 32

typedef JavaObject *Object;

typedef struct Array {
    int length;
    int capacity;
    Object *value;
} Array;

Array *newArray();

void addElement(Array *array, Object object);

Array *removeIndexAt(Array *array, int index);

Array *insertIndexAt(Array *array, Object object, int index);

Object getObjectIndexAt(Array *array, int index);

int getArrayLength(Array *array);

void destroyArray(Array *array);

void printArray(Array *array);

#endif //BASEDATASTRUCT_ARRAY_H
