#include <stdio.h>



int main() {
    printf("Hello, World!\n");
}

void moveZeroes(int* nums, int numsSize){
if (nums == NULL || numsSize == 0) {
        return;
    }

    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];        
            if (i != j) {
                nums[i] = 0;
            }
            j++;
        }
    }
}
