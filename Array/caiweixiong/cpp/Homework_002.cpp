//
// Created by Vashon on 2020/7/24.
//

#include "Homework_002.h"
#include <iostream>

using namespace std;

int Homework_002::climbStairs_1(int n) {
    int substep(int current, int target);
    return substep(0, n);
}

int Homework_002::climbStairs_2(int n) {
    int step = 1, first = 0, second = 0;
    for (int i = 1; i <= n; ++i) {
        first = second;
        second = step;
        step = first + second;
    }
    return step;
}

int substep(int current, int target) {
    if (current > target)
        return 0;
    if (current == target)
        return 1;
    return substep(current + 1, target) + substep(current + 2, target);
}

void Homework_002::homework_002_070() {
    int i;
    cout << "输入目标阶梯数字：" << endl;
    cin >> i;
    cout << "共有 " << climbStairs_2(i) << " 种爬楼梯方法" << endl;
}