#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target);
int main() {
    printf("Hello, World!\n");
    int numbers[] = {0,0,2, 7, 11, 15};
    int resurnSize;
    int target = 0;
    int numbersSize = sizeof(numbers)/sizeof(int);
   int *result = twoSum(numbers, numbersSize, target, &resurnSize);
    printf( "[%d,%d]",result[0], result[1]);

    return 0;
}
/**
 *
167. 两数之和 II - 输入有序数组
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

 采用双指针缩减搜索空间的角度思考  替代 双重循环
 */
int* twoSum(int* numbers, int numbersSize, int target){
    int i = 0, j=numbersSize-1;
    int* array = (int *)malloc(sizeof(int)*2);
    *array = -1;
    *(array+1) = -1;
    if(NULL == numbers)return array;
    while(i<j){
        int sum = *(numbers+i)+*(numbers+j);
        if(target>sum){
            i++;
        }else if(target<sum){
            j--;
        }else{
            *array = i+1;
            *(array+1) = j+1;
            break;
        }
    }
    return array;
}
