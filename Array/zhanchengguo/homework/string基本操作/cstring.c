#include <stdio.h>
#include <stdlib.h>
#include "cstring.h"

int main() {
    // 字符串复制函数测试
//    char *src = "hello strcpy";
//    char *dest = malloc(sizeof(char));
//    printf("copy dest : %s\n", my_strcpy(dest, src));

    // 字符串拼接函数测试
//    char *src1 = "hello strcpy";
//    char *dest1 = "dest";
//    printf("cat dest : %s\n", my_strcat(dest1, src1));

    // 字符串包含小串测试
//    char *haystack = "hello strcpy";
//    char *needle = "cpy";
//    printf("contains str : %s\n", my_strstr(haystack, needle));

    // 字符串包含字符测试
//    char *str = "http://www.baidu.com";
//    char ch = '.';
//    printf("contains char after : %s\n", my_strchr(str, ch));

    // 数组复制测试
    char *src = "hello memcpy";
    char dest[20] = {'\0'};
    my_memcpy(dest, src, 13);
    printf("dest : %s\n", dest);

    return 0;
}


char *my_strcpy(char *dest, char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char *temp = dest;
    while (*src != NULL) {
        *dest++ = *src++;
    }
    *dest = NULL;
    return temp;
}

char *my_strcat(char *src1, char *src2) {
    if (src1 == NULL || src2 == NULL) {
        return NULL;
    }
    char *temp = src1;
    while (*src1 != NULL) {
        src1++;
    }
    while (*src2 != NULL) {
        *src1++ = *src2++;
    }
    src1 = NULL;
    return temp;
}

char *my_strstr(char *src, char *dest) {
    if (src == NULL || dest == NULL) {
        return NULL;
    }
    char *bigPre = src;
    char *bigNext = src;
    char *np = dest;
    while (*bigPre != NULL) {
        if (*np == NULL) {
            return dest;
        }
        if (*bigPre == NULL) {
            return NULL;
        }
        if (*bigNext == *np) {
            bigNext++;
            np++;
        } else {
            bigPre++;
            bigNext = bigPre;
            np++;
        }
    }
    return NULL;
}

char *my_strchr(char *src, char dest) {
    if (src == NULL) {
        return NULL;
    }
    while (*src != NULL) {
        if (*src == dest) {
            break;
        }
        src++;
    }
    return src;
}


void *my_memcpy(char *dest, char *src, size_t n) {
    if (dest == NULL || src == NULL || n < 0) {
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        *dest++ = *src++;
    }

}


