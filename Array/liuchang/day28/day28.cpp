//
// Created by 刘畅 on 2020/6/28.
//

#include "day28.h"
#include "iostream"

int numOfSubarrays(int *arr, int arrSize, int k, int threshold);

int numOfSubarrays(int *arr, int arrSize, int k, int threshold) {

    int count = 0;
    for (int i = 0; i < arrSize - k + 1; i++) {
        int num = 0;
        for (int j = i; j < i+k; ++j) {
            num += arr[j];
        }
        if (num / k >= threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    int datas[] = {2, 2, 2, 2, 5, 5, 5, 8};
    printf("%d\n", numOfSubarrays(datas, 8, 3, 4));
    return 0;
}