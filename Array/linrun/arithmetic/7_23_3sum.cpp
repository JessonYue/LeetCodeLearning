#include<stdlib.h>
#include<stdio.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void merge(int* array, int start, int end);
void mergeOnce(int* array, int start, int end, int mid);

int main() {
    int ary[8] = {1,1,3,2,6,0, -1, -2};
    threeSum(ary, 8, NULL, NULL);
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    merge(nums, 0, numsSize-1);
    for (int j = 0; j < numsSize; j++ ){
        printf("Element[%d] = %d\n", j, nums[j] );
    }
    int* pre1 = NULL;
    int* pre2 = NULL;
    int* pre3 = NULL;
    int* cur1 = NULL;
    int* cur2 = NULL;
    int* cur3 = NULL;
    int index = 0;
    int count = 0;
    int ** ret = (int **)malloc(sizeof(int *) * (numsSize - 2) * 3);
    while(index<numsSize-2){
        cur1 = nums + index++;
        if(pre1 && (*cur1 == *pre1)){
            continue;
        }
        cur2 = cur1 + 1;
        cur3 = nums + numsSize -1;
        while(cur2 != cur3){
            if(pre2&&(*cur2 == *pre2)){
                cur2++;
                continue;
            }
            if(pre3&&(*cur3 == *pre3)){
                cur3--;
                continue;
            }
            if(*cur1 + *cur2 + *cur3 >0){
                pre3 = cur3;
                cur3--;
            }else if(*cur1 + *cur2 + *cur3 <0){
                pre2 = cur2;
                cur2++;
            }else{
                ret[count] = malloc(sizeof(int) * 3);
                ret[count][0] = *cur1;
                ret[count][1] = *cur2;
                ret[count][2] = *cur3;
                printf("first:%d  sec:%d  third: %d\n", ret[count][0], ret[count][1], ret[count][2]);
                pre2 = cur2;
                cur2++;
                count++;
            }
        }
        pre1 = cur1;
    }
    *returnSize = count;
    return ret;

}


void merge(int* array, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (end +start)/2;
    merge(array, start, mid);
    merge(array, mid+1, end);
    mergeOnce(array, start, end, mid);

}

void mergeOnce(int* array, int start, int end, int mid){
    if(start >= end){
        return;
    }
    int formerSize = mid - start + 1;
    int latterSize = end - mid;
    int* former = (int*)malloc(sizeof(int)*formerSize);
    int* latter = (int*)malloc(sizeof(int)*latterSize);
    for(int m=0; m<formerSize; m++){
        former[m] = array[start+m];
    }
    for(int n=0; n<formerSize; n++){
        latter[n] = array[mid+1+n];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<formerSize&&j<latterSize){
        if(former[i]<latter[j]){
            array[k++]=former[i++];
        }else{
            array[k++]=latter[j++];
        }
    }
    while(i<formerSize){
        array[k++]=former[i++];
    }
    while(j<latterSize){
        array[k++]=latter[j++];
    }
    free(former);
    free(latter);

}

