//
// Created by 吴超 on 2020/7/15.
//
#include <stdlib.h>

int firstUniqChar(char *s) {
    int index = 0;
    int *count = calloc(26, sizeof(int));
    while (s[index] != '\0') {
        count[s[index] - 'a']++;
        index++;
    }
    index = 0;
    while (s[index] != '\0') {
        if (count[s[index] - 'a'] == 1) {
            return index;
        }
        index++;
    }
    return -1;
}
