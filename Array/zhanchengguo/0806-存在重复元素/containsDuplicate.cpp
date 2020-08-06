#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.count(nums[i])) {
            return true;
        }
        map[nums[i]] = true;
    }
    return false;
}

int main() {
    int a[] = {1, 2, 3, 4};
    vector<int> v(a, a + 4);
    bool result = containsDuplicate(v);
    printf("result is %d", result);
    return 0;
}