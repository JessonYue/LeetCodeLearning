//
// Created by 刘畅 on 2020/6/22.
//

#include "day21.h"
#include <iostream>

int arrayNesting(int *nums, int numsSize);

int arrayNesting(int *nums, int numsSize) {
    int numData = 0;
    int data[numsSize];
    int dataCount = 0;
    for (int i = 0; i < numsSize; ++i) {
        data[dataCount] = nums[numData];
        numData = nums[numData];
        if (data[0] == numData && dataCount > 1) {
            break;
        }
        dataCount++;

    }
    return dataCount;
}

int main() {
    int data[] = {5, 4, 0, 3, 1, 6, 2};
    printf("+++++++%d\n", arrayNesting(data, 7));
}
