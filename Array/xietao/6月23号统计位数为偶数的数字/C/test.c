//
// Created by 谢涛 on 2020/4/17.
//

#include <stdio.h>

int getNumber(int a){
    int number = 0;
    while(a != 0){
        a = a/10;
        number++;
    }
    return number;
}
int findNumbers(int* nums, int numsSize){
    int res = 0;
    for(int i = 0; i < numsSize; i++){
        if((getNumber(nums[i]) &1) == 0){
            res++;
        }
    }
    return res;
}
 int main(){
}
