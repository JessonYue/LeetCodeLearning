//
// Created by 谢涛 on 2020/6/3.
//

#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);
int main() {
    int names[] = {2,7,11,15};
    int numbersSize = 4;
    int target = 9;
    int size = 0;
    int *newNum = twoSum(names,numbersSize, target, &size);


    if (size == 0){
        printf("没有查询到\n");
         free(newNum);
         return 0;
    }
    int start = newNum[0];
    int end = newNum[1];
    printf("start=%d\n",start);
    printf("end=%d\n",end);
    free(newNum);
    return 0;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0;
    int right = numbersSize - 1;
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum > target){
            right = right -1;
        }else if(sum < target){
            left = left + 1;
        }else{
            break;
        }
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int)*2);
    res[0] = left +1;
    res[1] = right +1;
    return res;
}



