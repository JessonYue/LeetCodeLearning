#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums);

int main() {
    int a[] = {0, 0, 1};
    vector<int> vv(a, a + 3);
    moveZeroes(vv);
    for (int i = 0; i < vv.size(); ++i) {
        printf("values is %d\n", vv[i]);
    }
    return 0;
}

/**
 * 思路：先把所有的非0数据保持原有顺序，之后在补0
 * @param nums
 */
void moveZeroes(vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }
    for (int i = index; i < nums.size(); i++) {
        nums[index++] = 0;
    }
}
