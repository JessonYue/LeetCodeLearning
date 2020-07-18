//
// Created by 胡扬 on 2020/7/17.
// C语言实现strcpy（字符串复制）、strcat（字符串链接）、
// strstr（字符串包含）、strchr（字符出现位置）、memcpy（拷贝）。主要熟悉指针高级用法。
//


#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

//获取字符串的信息
int mystrlen(char* str){
    int count = 0;
    while (*str!='\0'){
        count++;
        str++;
    }
    return count;

}

void strcpy(char * dst , char * src){
    while(*src){
        printf("%d",*src);
        *dst = *src;
        dst++;
        src++;
    }
    *dst ='\n';
}

void strcat(char * dst , char * src){
    while (*dst != '\0'){
        dst++;
    }
    while(*src !='\0'){
        *dst = *src;
        dst++;
        src++;
    }
    dst = '\0';
}
void strstr(char * dst , char * src){
    dst = src;
}
int strchr(char  dst , char * src){
    printf("str1 = %s ",src);

    int i = 0 ;
    while(*src != '\0'){
        printf(" %d \n",*src);
        printf(" %d ",dst);

        if(*src == dst){
            return i;
        }
        src++;
        i++;
    }
    return -1;

}
void memcpy(char * dst , char * src){
    dst = src;
}

void swap(char *a , char * b){
   int temp = *b;
   *b = *a;
   *a = temp;
}

void* mymemcpy(void *dest , const void * src, int count){

    char* a = dest;
    char* b = src;


    while (count != 0){
        *(a) = *b;
        a++;
        b++;
        count--;
    }

}

void main(){
    char str1 [10]="121";
    char str2 []="abced";
    char a = 'b';
    printf(" %d ",a);

//    strcpy(str1, str2);
//    strcat(str1, str2);
//      strstr(str1,str2);
//    strchr(a, str2);
    mymemcpy(str1, str2, 10);
    printf("str1 = %s , str2 = %s",str1,str2);
}