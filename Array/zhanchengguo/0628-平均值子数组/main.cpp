#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold);

int main() {
    int a[] = {2, 2, 2, 2, 5, 5, 5, 8};
    vector<int> v(a, a + 8);
    int result = numOfSubarrays(v, 3, 4);
    printf("params2 is %d", result);
    return 0;
}

/**
 * 思路：遍历数组，不断后移，移除当前的值，添加指定长度的下一个值，判断是否大于总和
 * @param arr
 * @param k
 * @param threshold
 * @return
 */
int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int length = arr.size();
    int sum = 0;
    int count = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    if (sum >= (k * threshold)) {
        count++;
    }
    if (length == k) {
        return count;
    }
    for (int j = 0; j < length - k; j++) {
        sum -= arr[j];
        sum += arr[j + k];
        if (sum >= (k * threshold)) {
            count++;
        }
    }
    return count;
}



