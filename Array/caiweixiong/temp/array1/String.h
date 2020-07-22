//
// Created by Vashon on 2020/7/21.
//

#ifndef BASEDATASTRUCT_STRING_H
#define BASEDATASTRUCT_STRING_H

#include "Object.h"
#include <string.h>

typedef struct String {
    int retainCount;
    char *value;
} String;

// 创建一个 String 对象
String *newString(char *value);

// 获取对象内的值
char *getStringValue(String *string);

// 回收字符串对象
void releaseString(String *string);

#endif //BASEDATASTRUCT_STRING_H
