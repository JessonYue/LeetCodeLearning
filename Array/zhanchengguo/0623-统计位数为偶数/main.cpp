#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

int findNumbers(vector<int> &nums);

int main() {
    int b[5] = {12, 345, 2, 6, 7896};
    vector<int> a(b, b + 5);
    int count = findNumbers(a);
    printf("params2 is %d", count);
    return 0;
}

/**
 * 思路：把int类型的数据转成字符串，根据字符串的长度除以2求余，
 * 根据结果是否等于2，判断是否为偶数位
 * @return
 */
int findNumbers(vector<int> &nums) {
    int count = 0;
    for (int num:nums) {
        if (to_string(num).size() % 2 == 0) {
            count++;
        }
    }
    return count;
}




