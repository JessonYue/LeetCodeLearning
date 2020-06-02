#include <iostream>
#include "vector"

int calcuate1(int i);

int calcuate(int n);

/**
 * 想到的第一种方式是使用递归来进行处理，但是发现在数据比较大时，耗时较长
 * 后面改成来数组来进行处理，耗时相对较小
 * @return
 */
int main() {
    int value = calcuate1(4);
    int moreValue = calcuate(4);
    printf("value is %d, morevalue is %d\n", value, moreValue);
    return 0;
}

int calcuate1(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n > 2) {
        return calcuate1(n - 1) + calcuate1(n - 2);
    }
    return -1;
}

int calcuate(int n) {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    for (int i = 2; i < n; i++) {
        nums.push_back(nums[i - 1] + nums[i - 2]);
    }
    return nums[n - 1];
}
