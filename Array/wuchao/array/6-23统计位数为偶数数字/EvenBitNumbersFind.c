#include <string.h>
//
// Created by 吴超 on 2020/6/23.
//
int getBitCounts(int num);
//先计算出每个数字的位数，然后这个位数&1，大于0的就是奇数，等于0的就是偶数
int findNumbers(int* nums, int numsSize){
    int count = 0;
    for(int i = 0;i<numsSize;i++){
        int bitCount = getBitCounts(nums[i]);
        if((bitCount&1)==0){
            count++;
        }
    }
    return count;
}

int getBitCounts(int num){
    int count=1;
    int mod=num;
    while((mod = mod/10)>=1){
        count++;
    }
    return count;
}
