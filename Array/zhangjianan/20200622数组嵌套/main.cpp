//
// Created by 张佳男 on 2020/6/9.
//

#include <iostream>
#include <cstring>

int arrayNesting(int* nums, int numsSize){
    int result = 0;
    for(int i=0;i<numsSize;i++){
        int count=0, k=i;
        while(nums[k]!=-1){
            count++;
            int tmp = nums[k];
            nums[k] = -1;
            k = tmp;
        }
        result =result>count?result:count;
    }
    return result;
}


int main() {
    int a[7]={5,4,0,3,1,6,2};
    std::cout << arrayNesting(a,sizeof(a)/sizeof(int )) << std::endl;
    return 0;
}