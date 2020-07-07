//
// Created by 谢涛 on 2020/6/30.
//
#include <stdio.h>
int main() {

    return 0;
}
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int sum = 0 , result = 0;
    int sumh = k * threshold;
    for(int i = 0; i < k; i++){
        sum = sum + arr[i];
    }
    int sy = sum - sumh;
    if(sy >= 0)
        result++;

    int pos = k;
    for(int i = 0; i < arrSize - k; i++){
        sy = sy + arr[pos] - arr[i];
        if(sy >= 0)
            result++;
        pos++;
    }
    return result;

}
