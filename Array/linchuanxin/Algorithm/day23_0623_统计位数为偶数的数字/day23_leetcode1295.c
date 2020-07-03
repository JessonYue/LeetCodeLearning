//
// Created by LCX on 2020/6/23.
//
#include <stdio.h>


int findNumbers(int* nums, int numsSize){

    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        int count = 0;
        int index = *(nums+i);
        for (;index; ) {
        //while (index) {
            index = index/10;
            count++;
        }
        if (count % 2 == 0)
            sum = sum+1;

    }
    return sum;
}


int main(){
//    int index = 12;
//    int count = 0;
//    for (;index; ) {
//        index = index/10;
//        count++;
//    }
//    printf("num sum count: %d\n",count);
    //int arr[] = {12,345,2,6,7896};
    int arr[] = {437,315,322,431,686,264,442};
    printf("%d\n",findNumbers(arr,7));
    return 0;
}