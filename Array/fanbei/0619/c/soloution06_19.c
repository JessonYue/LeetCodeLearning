#include <stdio.h>
#include <stdlib.h>


char *removeDuplicates2(char *s) {
    if (s == NULL || s[0] == 0) {
        return s;
    }
    int top = 0;
    int i = 1;
    while (s[i]) {
        if (top >= 0 && s[top] == s[i]) {
            top--;
        } else {
            s[++top] = s[i];
        }
        i++;
    }
    s[top + 1] = 0;
    return s;
}

