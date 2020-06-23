//
// Created by 张俊伟 on 2020/6/23.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
bool isEvenBit(int num){
    bool res;
    int count = 0;//位数
    do {
        num = num/10;
        count++;
    }while (num!=0);
    res = count%2==0;
    return res;
}

int findNumbers1(int* nums, int numsSize){
    int *p = nums;
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (isEvenBit(*(p+i))){
            count++;
        }
    }
    return count;

}
//8 ms	7 MB
int findNumbers2(int* nums, int numsSize){
    int count = 0;
    char **strNum = (char **)malloc(sizeof(char*)*numsSize);
    for (int i = 0; i < numsSize; ++i) {
       *(strNum+i) = (char *)malloc(sizeof(char)*7);
    }

    for (int j = 0; j < numsSize; ++j) {
        sprintf(*(strNum+j),"%d",*(nums+j));
       if(strlen(*(strNum+j))%2==0)
           count++;
    }
    for (int i = 0; i < numsSize; ++i) {
       free(*(strNum+i));
    }
    free(strNum);
    return count;

}
/**
 *
 * 16 ms	6.8 MB
 */
int findNumbers(int* nums, int numsSize){
    int count = 0;
    char **strNum = (char **)malloc(sizeof(char*)*numsSize);
    for (int i = 0; i < numsSize; ++i) {
        strNum[i] = (char *)malloc(sizeof(char)*7);
    }

    for (int j = 0; j < numsSize; ++j) {
        sprintf(strNum[j],"%d",nums[j]);
        if(strlen(strNum[j])%2==0)
            count++;
    }
    for (int i = 0; i < numsSize; ++i) {
        free(strNum[i]);
    }
    free(strNum);
    return count;

}