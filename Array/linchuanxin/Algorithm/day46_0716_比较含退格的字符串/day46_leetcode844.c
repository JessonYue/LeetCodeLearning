//
// Created by LCX on 2020/7/16.
//

#include <stdio.h>
#include <stdbool.h>

int strlen(const char *str)
{
    if(str == NULL)
        return -1;
    int count = 0;
    while (*str++)
        count++;
    return count;
}

int returnDeleteStrLength(char *str,int size)
{
    if(str == NULL || size == 0)
        return 0;
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if(str[i] != '#')
        {
            //index++;
            str[index++] = str[i];
        }
        else
        {
            if(index>0)
                index--;
        }
    }
    return index;
}


bool backspaceCompare(char * S, char * T){
    int s_length = returnDeleteStrLength(S,strlen(S));
    int t_length = returnDeleteStrLength(T,strlen(T));

    if(s_length != t_length)
        return false;
    for (int i = 0; i < s_length; ++i) {
        if(S[i] != T[i])
            return false;
    }
    return true;
}

