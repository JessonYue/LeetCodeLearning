#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
void quick_sort(int *array,int start,int end)
{
    int i,j,t,temp;
    if(start>end)
        return;
    temp=array[start];
    i=start;
    j=end;
    while(i!=j){
        while(array[j]>=temp && i<j){
            j--;
        }
        while(array[i]<=temp && i<j){
            i++;
        }
        if(i<j){
            t=array[i];
            array[i]=array[j];
            array[j]=t;
        }
    }
    array[start]=array[i];
    array[i]=temp;
    quick_sort(array,start,i-1);
    quick_sort(array,i+1,end);
}