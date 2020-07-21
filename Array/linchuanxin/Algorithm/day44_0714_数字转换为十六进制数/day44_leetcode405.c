//
// Created by LCX on 2020/7/14.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *reverse(char *str)
{
    if(str==NULL)
        return NULL;
    int len=strlen(str);
    int i=0;
    while(i<len-i-1){
        str[i]=str[i]^str[len-i-1];
        str[len-i-1]=str[i]^str[len-i-1];
        str[i]=str[i]^str[len-i-1];
        i++;
    };
    return str;

}



char * toHex(int num){
    char arr[]="0123456789abcdef";
    int count = -1;
    char *str = (char*)malloc(sizeof(char)*100);
    unsigned int num1 = num;
    while (num1 != 0 )
    {
        int index = num1&15;
        str[++count] =  arr[index];
        num1 = num1 >> 4;
    }

    if(str==NULL)
        return NULL;
    int len=strlen(str);
    int i=0;
    while(i<len-i-1){
        str[i]=str[i]^str[len-i-1];
        str[len-i-1]=str[i]^str[len-i-1];
        str[i]=str[i]^str[len-i-1];
        i++;
    };
    return str;
}





int main(void)
{
    printf("%s\n",toHex(26));
   // printf("%s\n",toHex(26));
    //char arr[]="0123456789abcdef";
//    char * res = (char*)malloc(9);
//    res = arr[10];
   // printf("%s\n",arr);
}