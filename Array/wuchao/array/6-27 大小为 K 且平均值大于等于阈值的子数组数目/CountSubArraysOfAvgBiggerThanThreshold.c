//
// Created by 吴超 on 2020/6/27.
//
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int i=0,j=1,sum=0,count=0;
    int thresholdK = 0;
    while(i<k){
        thresholdK+=threshold;
        sum+=arr[i++];
    }
    if(sum>=thresholdK) count++;
    while(i<arrSize){
        sum += (arr[i++]-arr[j++-1]);
        if(sum>=thresholdK) count++;
    }
    return count;
}
