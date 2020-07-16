//
// Created by 吴超 on 2020/7/16.
//
#include <stdlib.h>
#include <stdio.h>

/**
 * C语言实现strcpy（字符串复制）、strcat（字符串链接）、strstr（字符串包含）、strchr（字符出现位置）、memcpy（拷贝）
 */
char *strcpy(char *source);

char *strcat(char *dest, char *source);

int strstr(char *dest, char *source);

int strchr(char *source, char target);

void* memcpy(char *dest, char* source, size_t size);

size_t stringLen(char *source);

char *strcpy(char *source) {
    char *dest = malloc(stringLen(source) * sizeof(char));
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    return dest;
}

char *strcat(char *dest, char *source) {
    int destLen = stringLen(dest);
    int sourceLen = stringLen(source);
    char *result = malloc((destLen + sourceLen) * sizeof(char));
    int i = 0;
    while (i < destLen) {
        result[i] = dest[i];
        i++;
    }
    int j = 0;
    while (j < sourceLen) {
        result[i] = source[j];
        i++;
        j++;
    }
    return result;
}

int strstr(char *dest, char *source){
    int i = 0;
    int j = 0;
    int destLen = stringLen(dest);
    int sourceLen = stringLen(source);
    if(sourceLen>destLen) return -1;
    while(i<destLen){
        if(dest[i]==source[j]){
            i++;
            j++;
            if(j==sourceLen){
                return i-sourceLen;
            }
            continue;
        } else {
            i++;
            j=0;
        }
    }
    return -1;
}

int strchr(char *source, char target){
    int i = 0;
    while(source[i]!='\0'){
        if(source[i]==target){
            return i;
        }
        i++;
    }
}

void* memcpy(char *dest, char* source, size_t size){
    int i =0;
    int destLen = stringLen(dest);
    int sourceLen = stringLen(source);
    while(i<size&&i<sourceLen){
        dest[i] = source[i];
        i++;
    }
    if(i<destLen){
        dest[i] = '\0';
    }
    return dest;
}

size_t stringLen(char *source) {
    int i = 0;
    while (source[i++] != '\0') {

    }
    return i-1;
}

int main() {
    char *a = "asdfwer";
    char *b = strcpy(a);
    printf("copy:%s\n", b);
    printf("strcat:%s\n", strcat(a, "hello"));
    printf("strstr:%d\n", strstr("helloword","helloworld"));
    printf("strchr:%d\n", strchr("helloword",'l'));
    printf("memcpy:%s\n", memcpy(malloc(sizeof(char)),"helloworld",5));
}

