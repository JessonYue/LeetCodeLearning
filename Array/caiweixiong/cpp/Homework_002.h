//
// Created by Vashon on 2020/7/24.
//

#ifndef HOMEWORK_HOMEWORK_002_H
#define HOMEWORK_HOMEWORK_002_H


class Homework_002 {
private:
    // 方法一：递归
    int climbStairs_1(int n);
    // 方法二：动态规划，通过观察，结果依赖于前两项的和，f(x) = f(x - 1) + f(x - 2)
    int climbStairs_2(int n);
public:
    // 爬楼梯，LeetCode第70题
    void homework_002_070();
};


#endif //HOMEWORK_HOMEWORK_002_H
