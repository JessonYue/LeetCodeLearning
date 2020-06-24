//
// Created by hasee on 2020/6/23.
//
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int numberLength(int num) {
    int length = 1;
    while (num / 10) {
        num /= 10;
        length++;
    }
    return length;
}

int findNumbers(vector<int> &nums) {
    int count = 0;
    for (int num : nums) {
        if (numberLength(num) % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {100, 10, 23};
    int count = findNumbers(nums);
    cout << count << endl;
    return 0;
}