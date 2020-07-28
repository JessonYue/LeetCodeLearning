//
// Created by Vashon on 2020/7/22.
//

#ifndef HOMEWORK_HOMEWORK_001_H
#define HOMEWORK_HOMEWORK_001_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Homework_001 {
private:
    // 方法一：暴力法
    vector<int> twoSum_1(vector<int> &nums, int target);

    // 方法二：排序 + 二分查找
    vector<int> twoSum_2(vector<int> &nums, int target);

    // 方法三：散列表思想
    vector<int> twoSum_3(vector<int> &nums, int target);

public:
    // 两数之和II，注意，它们是有序表，LeetCode第1题
    void homework_001_001();
};


#endif //HOMEWORK_HOMEWORK_001_H
