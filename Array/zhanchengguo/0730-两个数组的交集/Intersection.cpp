#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * unordered_set存储数据不重复，利用这一特性进行处理
 */
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> numSet(nums1.begin(), nums1.end());
    unordered_set<int> ans;
    for (int num:nums2) {
        if (numSet.count(num) == 1) {
            ans.insert(num);
        }
    }
    return vector<int>(ans.begin(), ans.end());
}

int main() {
    int a[] = {1, 2, 2, 1};
    vector<int> v1(a, a + 4);
    int b[] = {2, 2};
    vector<int> v2(b, b + 2);
    vector<int> result = intersection(v1, v2);
    for (int res:result) {
        printf("value is %d\n", res);
    }
    return 0;
}
