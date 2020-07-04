//
// Created by LCX on 2020/6/29.
//


#include <stdio.h>


int numOfSubarrays(int* arr, int arrSize, int k, int threshold);

int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int standSum = k * threshold;
    int count = 0,sum = 0;

    for (int i = 0; i < k; ++i) {
        sum += *(arr+i);
    }

    if(sum >= standSum)
        count = 1;

    for (int j = k; j < arrSize; ++j) {
        sum -= arr[j-k];
        sum += arr[j];
        if(sum >= standSum)
            count++;
    }

    return count;

}


int main(void)
{
    int arr[] = {1,1,1,1,1};
    printf("%d\n",numOfSubarrays(&arr,5,1,0));

    return 0;
}
