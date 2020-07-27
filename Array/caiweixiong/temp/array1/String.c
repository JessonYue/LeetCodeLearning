//
// Created by Vashon on 2020/7/21.
//

#include "String.h"

String *newString(char *value) {
    String *string = malloc(sizeof(String));
    assert(string != NULL);
    string->retainCount = 0;
    int length = strlen(value) + 1;
    char *str = malloc(length * sizeof(char)); // 动态开辟空间，用于存放字符串对象
    strcpy(str, value);
    str[length - 1] = '\0'; // 字符串结束标记
    string->value = str;
    OBJ_RETAIN(string);
    return string;
}

char *getStringValue(String *string) {
    return string->value;
}

void releaseString(String *string) {
    if (getObjectRetainCount((Object *) string) == 1) {// 当引用计数为1且进行减少时，进行释放资源
        free(string->value);
        string->value = NULL;
        printf("String value free completed\n");
    }
    OBJ_RELEASE(string);
}