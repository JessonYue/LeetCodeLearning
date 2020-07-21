//
// Created by Vashon on 2020/7/20.
//

#ifndef BASEDATASTRUCT_INTEGER_H
#define BASEDATASTRUCT_INTEGER_H

#include "JavaObject.h"

typedef struct Integer {
    int retainCount;
    int value;
} Integer;

// 通过整型值创建一个整型对象
Integer *newInteger(int value);

// 获取 Integer 对象的值
int getIntegerValue(Integer *integer);

#endif //BASEDATASTRUCT_INTEGER_H
