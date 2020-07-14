#include <stdio.h>
#include <malloc.h>

/**
 * 387. 字符串中的第一个唯一字符
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 */
int firstUniqChar(char *s) {
    if (s == NULL) return -1;
    int *map = calloc(26, sizeof(int));
    int count = 0;
    while (s[count] != 0) {
        map[s[count++] - 'a']++;
    }

    for (int i = 0; i < count; i++) {
        if (map[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}