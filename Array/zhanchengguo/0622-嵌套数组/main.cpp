#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

int arrayNesting(vector<int> &nums);

int main() {
    int b[7] = {5, 4, 0, 3, 1, 6, 2};
    vector<int> a(b, b + 7);
    int count = arrayNesting(a);
    printf("params2 is %d", count);
    return 0;
}

/**
 * 思路：循环加标记的方式
 * 后续的数组点可以根据前一个点知道，循环遍历，进行count++,当遇到访问过的或者重复的终止循环
 * 和前一次循环的结果相比，取最大值
 * @param nums
 * @return
 */
int arrayNesting(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int count = 1;
        int value = nums[i];
        nums[i] = -1;
        while (value != nums[i] && nums[value] != -1) {
            value = nums[value];
            count++;
            nums[i] = -1;
        }
        res = max(res, count);
    }
    return res;
}




