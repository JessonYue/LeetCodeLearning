#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 两数之和
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result(2);
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        auto dx = target - nums[i];
        if (map.find(dx) != map.end()) {
            result[0] = dx;
            result[1] = nums[i];
            return result;
        }
        map.insert(make_pair(nums[i], i));
    }
    return result;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    //先找到最大值和最小值
    int *result = (int *) malloc(sizeof(int) * 2);
    int *array = (int *) malloc(sizeof(int) * target);
    *returnSize = 0;
    result[0] = 1;
    result[1] = 8;
    return result;
}


// 爬楼梯 直接使用记忆法
map<int, int> mp;

int climbStairs(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    auto ret = mp.find(n);
    if (ret != mp.end()) {
        return ret->second;
    }
    auto step1 = climbStairs(n - 1);
    mp.insert(make_pair(n - 1, step1));
    auto step2 = climbStairs(n - 2);
    mp.insert(make_pair(n - 2, step2));

    return step1 + step2;
}


int main() {

    vector<int> src = {1, 2, 6, 7};
    int target = 9;
    vector<int> ret = twoSum(src, target);
    for (int &iter : ret) {
        cout << iter << " ";
    }
    cout << endl;
    cout << climbStairs(45) << endl;
    return 0;
}




