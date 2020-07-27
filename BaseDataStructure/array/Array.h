//
// Created by Jesson on 2020/7/18.
//

#ifndef BASEDATASTRUCTURE_ARRAY_H
#define BASEDATASTRUCTURE_ARRAY_H
#include "JavaObject.h"
typedef JavaObject* AnyObject;

typedef struct Array{
    int length;
    int capacity;
    AnyObject *value;
}Array;

Array* newArray();

void addElement(Array *array,AnyObject value);
Array* removeIndexAt(Array *arry,int index);
Array* insertIndexAt(Array *array,AnyObject value,int index);
AnyObject getValueIndexAt(Array *array,int index);
int getArrayLength(Array *array);
void destroyArray(Array *array);
void printArray(Array *arr);

#endif //BASEDATASTRUCTURE_ARRAY_H
