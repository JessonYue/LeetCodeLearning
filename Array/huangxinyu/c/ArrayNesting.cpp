//
// Created by hasee on 2020/6/22.
//
#include <vector>
#include <stdio.h>

int arrayNesting(std::vector<int> &nums) {
    std::vector<int> visible(nums.size(), 0);
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (visible[i]) {
            continue;
        }
        int next = nums[i];
        int count = 0;
        do {
            next = nums[next];
            visible[next] = true;
            count++;
        } while (next != nums[i]);
        res = std::max(res, count);
    }
    return res;
}

int main() {
    std::vector<int> array = {5, 4, 0, 3, 1, 6, 2};
    int i = arrayNesting(array);
    printf("rest = %d", i);
    return 0;
}