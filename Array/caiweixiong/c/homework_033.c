//
// Created by Vashon on 2020/7/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

void moveZeroes(int *nums, int numsSize);

// 移动零，LeetCode第283题
void homework_033_283(void) {
    const int length = 5;
    int arr[5] = {0, 1, 0, 3, 12}, index;
    for (index = 0; index < length; ++index) {
        printf("%d ", arr[index]);
    }
    printf("\n");
    moveZeroes(arr, length);
    for (index = 0; index < length; ++index) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

void moveZeroes(int *nums, int numsSize) {
    // 步骤
    // 1.两个指针，一个指向前一位，一个指向后一位
    // 2.
    //      a.前一位为 0，后一位不为零，交换，两个指针都后移一位
    //      b.前一位为 0，后一位为零，前一位指针不变，后一位指针后移一位
    // 3.循环步骤2.b，直到变为步骤2.a
    // 4.当后一位的指针到达数组尾，则跳出循环
    if (!nums || numsSize <= 1)
        return;
    int pre = 0, next = 1;
    // 版本一：
//    while (next < numsSize) {
//        if (!nums[pre] && !nums[next])
//            next++;
//        else {
//            if (!nums[pre]) {
//                int temp = nums[pre];
//                nums[pre] = nums[next];
//                nums[next] = temp;
//            }
//            pre++, next++;
//        }
//    }
    // 版本二：
//    while (next < numsSize) {
//        if (nums[pre] || nums[next]) {
//            if (!nums[pre]) {
//                int temp = nums[pre];
//                nums[pre] = nums[next];
//                nums[next] = temp;
//            }
//            pre++;
//        }
//        next++;
//    }
    // 版本三：
    while (next < numsSize) {
        if (nums[pre] || nums[next]) {
            if (!nums[pre]) // 利用一个数异或同一个数两遍，结果不变的原理
                nums[pre] ^= nums[next] ^= nums[pre] ^= nums[next];
            pre++;
        }
        next++;
    }
}















