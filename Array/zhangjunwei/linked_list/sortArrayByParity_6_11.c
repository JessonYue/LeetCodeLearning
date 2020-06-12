//
// Created by 张俊伟 on 2020/6/11.
//
#include <stdlib.h>

int *sortArrayByParity(int *A, int ASize, int *returnSize) {
    *returnSize = ASize;
   int *result = (int *) malloc(sizeof(int) * ASize);
   if (result==NULL)return NULL;
    for (int k = 0; k < ASize; ++k) {
        result[k] = A[k];
    }
    int i = 0, j = ASize-1;
    while (i<j){
        if (result[i]%2>result[j]%2){
            int tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;
        }
        if (result[i]%2==0)i++;
        if (result[j]%2==1)j--;
    }
    return result;
}