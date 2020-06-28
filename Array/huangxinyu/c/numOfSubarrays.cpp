//
// Created by hasee on 2020/6/28.
//
#include <vector>

using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int sumThreshold = k * threshold;
    int size = arr.size();
    int ret = 0;
    if (size < k) {
        return ret;
    }
    int i = 0;
    int sum = 0;
    for (; i < k; ++i) {
        sum += arr[i];
    }
    int delta = sum - sumThreshold;
    if (delta >= 0) {
        ret++;
    }
    for (; i < size; ++i) {
        delta += (arr[i] - arr[i - k]);
        if (delta >= 0) {
            ret++;
        }
    }
    return ret;
}

int main() {

    return 1;
}