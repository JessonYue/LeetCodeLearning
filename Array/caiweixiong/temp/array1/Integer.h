//
// Created by Vashon on 2020/7/21.
//

#ifndef BASEDATASTRUCT_INTEGER_H
#define BASEDATASTRUCT_INTEGER_H

#include "Object.h"

typedef struct Integer {
    int retainCount;
    int value;  // 实际存放值的字段
} Integer;

// 创建一个 Integer 对象
Integer *newInteger(int value);

// 获取对象内的值
int getIntegerValue(Integer *integer);

#endif //BASEDATASTRUCT_INTEGER_H
