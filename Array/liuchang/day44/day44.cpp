//
// Created by 刘畅 on 2020/7/14.
//

#include "day44.h"
#include "string"

int firstUniqChar(char *str);

int firstUniqChar(char *str) {
    int length = strlen(str);
    printf("%d\n", length);
    int n = 0;
    while (str[n] != NULL) {
        int index = n;
        for (int i = 0; i < length; ++i) {
            if (str[index] == str[i] && i != index) {
                break;
            } else if (i == (length - 1)) {
                return n;
            }
        }
        index++;
        n++;
    }
    return -1;
}

int main() {
    int num = firstUniqChar("loveleetcode");
    printf("%d\n", num);
    return 0;
}
