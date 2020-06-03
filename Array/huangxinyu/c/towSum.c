#include <stdio.h>
#include <stdlib.h>

#define  MAX(a, b)  (a) > (b) ? (a) : (b)
#define  MIN(a, b)  (a) < (b) ? (a) : (b)

int binary_search(const int *nums, int pos, int numsSize, int target) {

    int l = pos, r = numsSize - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}


int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {

    if (nums == NULL) return NULL;
    int *res = (int *) malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        int mid = binary_search(nums, i + 1, numsSize, target - nums[i]);
        if (mid != -1) {
            res[0] = MIN(i, mid);
            res[1] = MAX(i, mid);
            break;
        }
    }

    return res;
}
