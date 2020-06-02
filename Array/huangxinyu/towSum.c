#include <stdio.h>

int twoSum(const int *numbers, int len, int target, int result[2]);

int main() {
    int array[] = {2, 7, 11, 15};
    int target = 9;
    int result[2] = {0,0};
    int ret = twoSum(array, 4, target, result);
    if (ret > 0) {
        printf("index1 = %d,intdex2 = %d", result[0], result[1]);
    }else{
        printf("not found");
    }
    return 0;
}

int twoSum(const int *numbers, int len, int target, int result[2]) {
    if (len < 2) return -1;
    int i = 0, j = len - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            result[0] = i;
            result[1] = j;
            return 1;
        }
        if (numbers[i] + numbers[j] < target) {
            i++;
        }else{
            j--;
        }
    }
    return -1;
}
