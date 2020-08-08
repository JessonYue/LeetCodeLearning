#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
void quick_sort(int *arr,int size)
{
    int i = 0;
    int j = 0;
    assert(arr);
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}