//
// Created by LCX on 2020/8/7.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
void quick_sort(int *arr,int sz)
{
//    if( len <= 1 ) return;
//
//    int i=0, j=len-1, t, temp = a[0];
//    while( i<j ) {
//        while( a[j]>temp && j>i ) j--; a[i] = a[j];
//        while( a[i]<=temp && i<j ) i++; a[j] = a[i];
//    }
//    a[i] = temp;
//    quick_sort(a, i);
//    quick_sort(a+i+1, len-i-1);
//
//    return;
    int i = 0;
    int j = 0;
    assert(arr);
    for(i=0;i<sz-1;i++){
        for(j=0;j<sz-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

bool containsDuplicate(int* nums, int numsSize){
//bool containsDuplicate(){
    //int* a = {1,3,5,7,9,2,4,6,8,10};
    quick_sort(nums, numsSize);
    for(int i=0; i<numsSize; i++) {
        if(i+1 < numsSize)
            if(nums[i] == nums[i+1])
                return true;
    }
    return false;



}

int main()
{
    containsDuplicate();
    return 0;
}