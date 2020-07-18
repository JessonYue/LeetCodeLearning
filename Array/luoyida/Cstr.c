//
// Created by xing on 2020/7/17.
//
#include <stdio.h>

#include <assert.h>
#include<stdlib.h>

/**
 * 字符串复制
 * @param sub
 * @param arr
 * @return
 */
char *Strcpy(char *sub, char *arr) {
    if (sub == NULL || arr == NULL)
        return NULL;
    char *tem = sub;//定义一个指针tem保存字符串首元素地址
    while (*arr != '\0')//复制字符串有效字符，遇到\0结束
    {
        *sub = *arr;//把arr的值给sub
        sub++;//每复制一次sub往后移一个
        arr++;//arr也往后移一个
    }
    *sub = '\0';//循环过程没有复制\0,所以循环结束后给sub所指的字符串赋\0
    return tem;//返回字符串地址
}

/**
 * 字符串链接
 * @param dst
 * @param src
 * @return
 */
char *Strcat(char *dst, const char *src) {
    assert(dst != NULL && src != NULL);
    char *temp = dst;
    while (*temp != '\0')
        temp++;
    while ((*temp++ = *src++) != '\0');

    return dst;
}

/**
 * 字符串包含
 * @param src
 * @param sub
 * @return
 */
const char *strstr(const char *src, const char *sub) {
    const char *bp;
    const char *sp;
    if (!src || !sub) {
        return src;
    }
    /* 遍历src字符串  */
    while (*src) {
        /* 用来遍历子串 */
        bp = src;
        sp = sub;
        do {
            if (!*sp)  /*到了sub的结束位置，返回src位置   */
                return src;
        } while (*bp++ == *sp++);
        src++;
    }
    return NULL;
}

/**
 * 字符出现位置
 * @param msg
 * @param dest
 * @return
 */
char *Strchr(const char *msg, char dest) {
    char *m = NULL;
    while (*msg != NULL) {
        if (*msg == dest) {
            return (char *) msg;
        }
        *msg++;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    char arr[] = "abcdddef";
    char sub1[] = {};
    Strcpy(sub1, arr);
    printf("%s\n", sub1);

    char arr1[] = "abcdddef";
    char arr2[] = "abcf";
    char arr3[] = "c";

    printf("%s\n", Strcat(arr1, arr2));
    printf("%s\n", strstr(arr1, arr2));
    printf("%s\n", Strchr(arr1, arr3));
    return 0;
}
