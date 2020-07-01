#include <stdio.h>

int numOfSubarrays(int *arr, int arrSize, int k, int threshold) {
    int sum=0,result=0;
    int thresholdsum=k*threshold;
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }
    int resultsum=sum-thresholdsum;
    if (resultsum>=0) {
        result++;
    }
    int pos=k;
    for (int j = 0; j < arrSize - k; ++j) {
        resultsum=resultsum+arr[pos]-arr[j];
        if (resultsum>=0) {
            result++;
        }
        pos++;
    }
    return  result;
}

int main() {
//    int arr[10] = {11,13,17,23,29,31,7,5,2,3};
    int arr[8] = {7,7,7,7,7,7,7};
    printf(numOfSubarrays(arr, sizeof(arr) / sizeof(arr[0]), 7, 7));
    return 0;
}
