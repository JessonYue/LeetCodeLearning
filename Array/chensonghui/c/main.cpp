#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

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
        map.insert( make_pair(nums[i], i));
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


int main() {

    vector<int> src = {1, 2, 6, 7};
    int target = 9;
    vector<int> ret = twoSum(src, target);
    for (int & iter : ret) {
        cout << iter << " ";
    }
    return 0;
}




