//
// Created by 张佳男 on 2020/6/9.
//

#include <iostream>
#include <cstring>

int findNumbers(int* nums, int numsSize){
    int j=0;
    for (int i = 0; i < numsSize; ++i) {
        if ((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000)||nums[i]==100000) j++;
    }
    return j;
}

int main() {
    int a[7]={12,345,2,6,7896};
    std::cout << findNumbers(a,sizeof(a)/sizeof(int )) << std::endl;
    return 0;
}