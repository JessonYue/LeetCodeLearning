#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//思路同java 思路
int main() {
    char haystack[] = {"hello"};
    char needle[] = {"ll"};
    int needleLength = sizeof(needle);
    for (int i = 0; i < sizeof(haystack); i++) {
        char *subch = (char *) calloc(sizeof(char), needleLength);
        strncpy(subch, haystack+i, needleLength-1);
        printf("%s\n",subch);
        if (strcmp(subch,needle)==0){
            printf("%i\n",i);
        }
    }
    return needleLength;

}