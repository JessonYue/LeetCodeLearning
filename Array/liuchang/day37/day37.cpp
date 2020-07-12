//
// Created by 刘畅 on 2020/7/7.
//

#include "day37.h"
#include "iostream"
#include "string"

char *changeString(char *strings);

char *changeString(char *strings) {
//    printf("%s\n", strings);
    int count = sizeof(strings);
    char *newString = new char[count];
    for (int i = count - 3; i >= 0; i--) {
//        printf("%c\n", strings[i]);
        for (int j = 0; j < count - 2; ++j) {
            if (newString[j] == NULL){
                newString[j] = strings[i];
                break;
            }
        }
    }
    return newString;
}

int main() {
    char *abc = "abcdef";
    printf("%s\n",changeString(abc));
    return 0;
};