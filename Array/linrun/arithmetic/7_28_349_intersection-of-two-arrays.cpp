//
// Created by Administrator on 2020/7/28.
//

//349. 两个数组的交集
//给定两个数组，编写一个函数来计算它们的交集。

//示例 1：

//输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* source, int startIndex, int endIndex);

void mergeOnce(int* source, int startIndex, int endIndex);

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    merge(nums1, 0, nums1Size-1);
    merge(nums2, 0, nums2Size-1);
    int* pre = NULL;
    int* ret = (int*)malloc(sizeof(int)*nums1Size);
    int index = 0;
    for(int i=0; i<nums1Size; i++){
        if(pre && *nums1 == *pre){
            *nums1++;
            continue;
        }
        int* comp = nums2;
        int* preComp = NULL;
        for(int j=0; j<nums2Size; j++){
            if(preComp && *preComp == *comp){
                *comp++;
                continue;
            }
            preComp = comp;
            if(*comp > *nums1){
                break;
            }else if(*comp < *nums1){
                *comp++;
            }else{
                ret[index++] = *nums1;
                break;
            }
        }
        pre = nums1;
        *nums1++;
    }
    *returnSize = index;
    return ret;

}


void merge(int* source, int startIndex, int endIndex){
    if(startIndex < endIndex){
        int mid = (startIndex+endIndex)/2;
        merge(source, startIndex, mid);
        merge(source, mid+1, endIndex);
        mergeOnce(source, startIndex, endIndex);
    }
}


void mergeOnce(int* source, int startIndex, int endIndex){
    if(startIndex>=endIndex){
        return;
    }
    int formerSize = (endIndex -startIndex)/2 +1;
    int latterSize = endIndex - startIndex + 1 - formerSize;
    int* former = (int*)malloc(sizeof(int)*formerSize);
    int* latter = (int*)malloc(sizeof(int)*latterSize);
    for(int m=0; m<formerSize; m++){
        former[m] = source[startIndex+m];
    }
    for(int n=0; n<latterSize; n++){
        latter[n] = source[startIndex+formerSize+n];
    }
    int i=0;
    int j=0;
    int k=startIndex;
    while(i<formerSize&&j<latterSize){
        if(former[i]<latter[j]){
            source[k++]=former[i++];
        }else{
            source[k++]=latter[j++];
        }
    }
    while(i<formerSize){
        source[k++]=former[i++];
    }
    while(j<latterSize){
        source[k++]=latter[j++];
    }
    free(former);
    free(latter);
}