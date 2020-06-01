//
// Created by 12 on 2020/5/31.
//

#include <stdio.h>
#include <malloc.h>


/**
 * 找到数组中等于目标值的索引
 */
int findFirst(int *numbers, int target, int left, int right) {
    if (numbers == NULL || left >= right) {
        return -1;
    }

    if (numbers[left] == target) {
        return left;
    }

    if (numbers[right] == target) {
        return right;
    }

    int mid = (right + left) / 2;
    if (numbers[mid] == target) {
        return mid;
    } else if (numbers[mid] > target) {
        findFirst(numbers, target, left, mid - 1);
    } else {
        findFirst(numbers, target, mid + 1, right);
    }
}

/**
 * 167. 两数之和 II - 输入有序数组
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 说明:
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 2);
    int i = 0, j = numbersSize - 1;
    *returnSize = 0;
    if (numbers == NULL) {
        return arr;
    }
    while (i < j) {
        int tmp = numbers[i] + numbers[j];
        if (tmp == target) {
            arr[0] = i + 1;
            arr[1] = j + 1;
            *returnSize = 2;
            return arr;
        } else if (tmp > target) {
            j--;
        } else {
            i++;
        }
    }

    return arr;
}

int climbStairs(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    int one = 1, two = 2, r = 0;
    //斐波那契数列，递归改用循环的方式实现，参考别人代码
    for (int i = 2; i < n; i++) {
        r = one + two;
        one = two;
        two = r;
    }

    return r;
}

int main() {
    printf("%d", climbStairs(4));
    return 0;
}