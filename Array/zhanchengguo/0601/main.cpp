#include <iostream>

/**
 * 目前想到的比较暴力的解法
 * @return
 */
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int index1;
    int index2;
    int size = sizeof(nums) / sizeof(int);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; ++j) {
            if ((nums[i] + nums[j]) == target) {
                index1 = i;
                index2 = j;
            }
        }
    }
    printf("index value is %d, %d\n", index1, index2);
    return 0;
}