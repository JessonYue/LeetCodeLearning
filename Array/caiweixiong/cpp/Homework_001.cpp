//
// Created by Vashon on 2020/7/22.
//

#include "Homework_001.h"
#include <iostream>

vector<int> Homework_001::twoSum_1(vector<int> &nums, int target) {
    vector<int> indexs;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (target == nums[i] + nums[j]) {
                indexs.push_back(i);
                indexs.push_back(j);
                return indexs;
            }
        }
    }
    return indexs;
}

vector<int> Homework_001::twoSum_2(vector<int> &nums, int target) {
    vector<int> indexs, temps = nums;
    sort(temps.begin(), temps.end());   // 排序
    int i = 0, j = temps.size() - 1;
    while (i < j) {
        if (temps[i] + temps[j] < target)
            i++;
        else if (temps[i] + temps[j] > target)
            j--;
        else
            break;  // 由于是排序过的数据，所以不能表示真正数组中的索引，跳出循环后再进行判断
    }
    if (i < j) {    // 找到了目标
        int half1 = temps[i], half2 = temps[j];
        for (int m = 0, n = temps.size() - 1; m <= n; ++m, --n) {
            if (half1 == nums[m] || half2 == nums[m])
                indexs.push_back(m);
            if (indexs.size() == 2) // 当两个目标值都找到就返回
                return indexs;
            if (half1 == nums[n] || half2 == nums[n])
                indexs.push_back(n);
            if (indexs.size() == 2) // 当两个目标值都找到就返回
                return indexs;
        }
    }
    return indexs;
}

vector<int> Homework_001::twoSum_3(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> hashmap;

    for (int i = 0, other = 0, num = 0; i < nums.size(); i++) {
        num = nums[i];
        other = target - num;
        /* 在这里 判断 如果 存在 target - nums[i] 对应的 值  并且这个值不是自己 */
        /* 映射关系  key->value,  key:target - nums[i],  value:myhash[target - nums[i]] */
        if (hashmap[other] && (hashmap[other] != i + 1)) {
            ans.push_back(i);
            ans.push_back(hashmap[other] - 1);
            return ans;
        }
        /* 数据哈希映射表，将hash表对应下标＋1，防止处理下标为 0 的情况 */
        hashmap[num] = i + 1;
    }

    return ans;
}

void Homework_001::homework_001_001() {
    std::vector<int> vector = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> ans = twoSum_1(vector, target);
    cout << "index 1 :" << ans[0] << " index 2 :" << ans[1] << endl;
}