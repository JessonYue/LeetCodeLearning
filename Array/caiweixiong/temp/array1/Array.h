//
// Created by Vashon on 2020/7/21.
//

#ifndef BASEDATASTRUCT_ARRAY_H
#define BASEDATASTRUCT_ARRAY_H

#include "Object.h"

#define DEFAULT_CAPACITY 32 // 默认的容量大小
#define ADD_ELEM(array, object) addElement(array, (Object *)object)

typedef struct Array {
    int capacity;           // 最大容量
    int length;             // 当前已经使用的长度
    Object **objects;       // 存放的对象真实容器，注意，所以这里必须是二级指针，存放的是一级指针的地址，这个容器是只存放对象地址的，而不是实际内容
} Array;

// 创建数组
Array *newArray();

// 得到数组的长度
int getArrayLength(Array *array);

// 添加元素，线性添加，从小到大
void addElement(Array *array, Object *object);

// 添加一个数组的元素
void addAll(Array *destArray, Array *srcArray);

// 插入元素，通过指定索引
void insertElement(Array *array, Object *object, int index);

// 通过索引获取对应的元素
Object *getElement(Array *array, int index);

// 删除元素，通过指定索引，由于自定义的对象数组，所以删除时给出一个回调，通知外面准备删除，外面可以做适当的资源回收
void removeElement(Array *array, int index, void (* callback)(Object *));

// 删除全部元素，由于自定义的对象数组，所以删除时给出一个回调，通知外面准备删除，外面可以做适当的资源回收
void removeAll(Array *array, void (* callback)(Object *));

// 打印数组，由于自定义的对象数组，所以具体的打印留给外面具体实现的时候再做，这里数组只做迭代并回调对象
void printArray(Array *array, void (* callback)(Object *));

// 释放数组
void destroyArray(Array *array);

#endif //BASEDATASTRUCT_ARRAY_H
