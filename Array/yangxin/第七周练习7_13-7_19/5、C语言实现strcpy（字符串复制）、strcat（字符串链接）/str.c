/**
 * C语言实现strcpy（字符串复制）、strcat（字符串链接）、strstr（字符串包含）、strchr（字符出现位置）、memcpy（拷贝）。主要熟悉指针高级用法。
 */
//字符串拷贝
char *str_copy(char *str) {
    int size = strlen(str);
    char *new_str = calloc(size, sizeof(char));
    for (int i = 0; i < size; i++) {
        new_str[i] = str[i];
    }

    return new_str;
}

//字符串链接
char *link_str(char *str1, char *str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int count = size1 + size2;
    char *new_str = calloc(count, sizeof(char));
    int index = 0;
    while (index < size1) {
        new_str[index] = str1[index];
        index++;
    }
    while (index < count) {
        new_str[index] = str2[index - size1];
        index++;
    }
    return new_str;
}

//字符串包含
int str_include_str(char *str1, char *str2) {
    int slen = strlen(str1);
    int plen = strlen(str2);

    int i = 0;
    int j = 0;
    while (i < slen && j < plen) {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == plen) {
        return i - j;
    } else {
        return -1;
    }
}

//字符出现位置
int str_chr(char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int index = 0;
    while (str[index] != 0) {
        if (str[index++] == c) {
            return index;
        }
    }
    return -1;
}

//拷贝
void *str_memcpy(void *dst, const void *src, size_t size) {
    if (NULL == dst || NULL == src || size <= 0) {
        return NULL;
    }
    char *pdst = (char *) dst;
    char *psrc = (char *) src;

    while (size--) {
        *(pdst++) = *(psrc++);
    }

    return dst;
}