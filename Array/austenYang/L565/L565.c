//
// Created by austenYang on 2020/6/22.
//

#include "L565.h"

int arrayNesting1(int *nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        int start = nums[i], count = 0;
        do {
            start = nums[start];
            count++;
        } while (start != nums[i]);

        if (count > res) res = count;
    }
    return res;

}

int arrayNesting2(int *nums, int numsSize) {
    int res = 0;
    int visited[numsSize];
    for (int j = 0; j < numsSize; ++j) {
        visited[j] = 0;
    }
    for (int i = 0; i < numsSize; ++i) {
        if (!visited[i]) {
            int start = nums[i], count = 0;
            do {
                start = nums[start];
                count++;
                visited[i] = true;
            } while (start != nums[i]);
            if (count > res) res = count;
        }

    }
    return res;
}


int arrayNesting3(int *nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        int count = 0;
        int index = i;
        while (nums[index] != -1) {
            int start = nums[index];
            index = start;
            nums[i] = -1;
            count++;
        }
        if (count > res) res = count;
    }
    return res;
}


