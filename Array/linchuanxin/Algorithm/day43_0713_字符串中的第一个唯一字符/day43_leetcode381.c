//
// Created by LCX on 2020/7/14.
//

#include <stdio.h>
#include <string.h>


int firstUniqChar(char * s){
    int count = 0;
    const char*	pSrc = s;
    if(pSrc == NULL)
    {
        count = -1;
        return count;
    }
    while (*pSrc++)
    {
        count++;
    }
    //int count = strlen(s);
    //printf("count:%d\n",count);
    printf("count1:%d\n",count);
    //int count = strlen(s);
    int flag[26] = {0};
    for (int i = 0; i < count; ++i) {
        int index = s[i] - 'a';
        flag[index]++;
    }

    for (int j = 0; j < count; ++j) {
        int index = s[j] - 'a';
        if(flag[index] == 1)
            return j;
    }

    return -1;
}

int main(void)
{

    char *s= "leetcode";
    printf("%d\n", firstUniqChar(s));
}

