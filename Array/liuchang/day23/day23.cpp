//
// Created by 刘畅 on 2020/6/23.
//

#include "day23.h"
#include "iostream"
#include "math.h"
int findNumbers(int* nums, int numsSize);

int findNumbers(int* nums, int numsSize){
    int count = 0;
    for (int i = 0; i <numsSize ; ++i) {
        int n  = 1;
        while (pow(10,n)<nums[i]){
            n++;
        }
        if (n%2 ==0){
            count++;
        }
    }
    return count;
}

int main(){
    int nums[] = {12,345,2,6,7896};
    printf("%d\n",findNumbers(nums,5));
    return 0;
}
