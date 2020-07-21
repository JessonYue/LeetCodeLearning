//
// Created by 刘畅 on 2020/7/17.
//

#include "day47.h"
#include "iostream"
#include "string"

bool backspaceCompare(char *S, char *T);

bool backspaceCompare(char *S, char *T) {
    for (int i = 0; i < strlen(S); ++i) {
        char a = S[i];
        char b = T[i];
        if (a == b && a != '#' && b != '#') {
            return true;
        }
    }
    return false;
}

int main() {
    char *S = "ab#c";
    char *T = "ad#c";
    printf("%d\n", backspaceCompare(S, T));
    return 0;
}