//
// Created by 张俊伟 on 2020/7/16.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//C语言实现 。主要熟悉指针高级用法。
// strcpy（字符串复制）、
char *my_strcpy(char *dest, const char *src) {
    char *tmp = dest;
//    while (*src){
//        *(tmp++) = *(src++);
//    }
    while ((*tmp++ = *src++) != '\0');
    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t count) {
    char *tmp = dest;
    while (count) {
        if ((*tmp = *src) != '\0')//若 src 的长度len小于 count  [len, count]部分填'\0'
            src++;
        tmp++;
        count--;
    }
    return dest;
}

// strcat（字符串链接）、
char *my_strcat(char *dest, const char *src) {
    char *tmp = dest;
    while (*tmp)
        tmp++;//移动到dest 字符串的尾部
    while ((*tmp++ = *src++) != '\0');
    return dest;

}

size_t my_strlen(const char *s) {
    char const *tmp = s;
    while (*tmp++ != '\0');
    return tmp - s;
}

int my_memcmp(const void *cs, const void *ct, size_t count) {
    const unsigned char *su1, *su2;
    int res = 0;

    for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
        if ((res = *su1 - *su2) != 0)
            break;
    return res;
}

// strstr（字符串包含）、
//返回值：若str2是str1的子串，则返回str2在str1的首次出现的地址；
// 如果str2不是str1的子串，则返回NULL。
char *my_strstr(char const *str1, const char *str2) {
    size_t len2 = my_strlen(str2);
    //str2 为空时
    if (!len2) return (char *) str1;
    size_t len1 = my_strlen(str1);
    while (len1 >= len2) {
        len1--;
        if (!my_memcmp(str1, str2, len2))//有子串
            return (char *) str1;
        str1++;
    }
    return NULL;
}

// strchr（字符出现位置）、
char *my_strchr(const char *s, int c) {
    for (; *s != (char) c; s++) {
        if (*s == '\0')
            return NULL;
    }
    return (char *) s;
}

// memcpy（拷贝）
void *my_memcpy(void *dest, const void *src, size_t count) {
//    char *tmp = dest;
//    const char *s = src;
//    while (count) {
//        if ((*tmp = *s) != '\0')
//            s++;
//        tmp++;
//        count--;
//    }
//    return dest;
    char *tmp = dest;
    const char *s = src;

    while (count--)
        *tmp++ = *s++;
    return dest;
}
void *my_memset(void *s, int c, size_t count)
{
    char *xs = (char *)s;

    while (count--)
        *xs++ = c;
    return s;
}
int main() {
    char *str1 = "hello";
    char *str2 = "22hello";
    int len = 1<<4;
    char *p = (char *) calloc(len, sizeof(char));
    my_memcpy(p, str2, len);
    printf("拷贝：%s\n", p);

    my_strcpy(p, str2);
    printf("字符串复制：%s\n", p);
    my_memset(p,0, len);
    my_strncpy(p,str1,len);
    printf("字符串复制_+ count：%s\n", p);
    my_strcat(p, str2);
    printf("字符串链接 ：%s\n", p);
    printf("字符串长度：%zu\n", my_strlen(p));
    p = my_strstr(str2,str1);
    printf("字符串包含：%s\n", p);
//    my_strchr(p, 'o');
    printf("字符出现位置：%s\n", my_strchr(p, 'o'));
//    memcpy（拷贝）
//    my_memset(p,0, len);
    return 0;
}