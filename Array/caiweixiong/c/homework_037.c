//
// Created by Vashon on 2020/8/5.
//

#include "homework_037.h"

int *intersection_1(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    if (nums1Size == 0 || nums2Size == 0 || !nums1 || !nums2) {
        *returnSize = 0;
        return NULL;
    }
    // 最大的交集不会超过两数组中最小的数组大小
    int max, min, index = 0, *n1, *n2; // n1 保存小数组，n2 保存大数组
    if (nums1Size < nums2Size) {
        min = nums1Size;
        max = nums2Size;
        n1 = nums1;
        n2 = nums2;
    } else {
        min = nums2Size;
        max = nums1Size;
        n1 = nums2;
        n2 = nums1;
    }
    int *nums = calloc(min, sizeof(int));
    assert(nums != NULL);
    for (int i = 0; i < min; ++i) {
        bool isExist = false;
        for (int j = 0; j < max; ++j) {
            if (n1[i] == n2[j]) {
                isExist = true;
                break;
            }
        }
        if (isExist) {    // 当大数组存在小数组同样的元素时
            isExist = false;
            for (int k = 0; k < index; ++k) {
                if (nums[k] == n1[i]) { // 过滤一遍，当数组中未添加该元素才需要添加
                    isExist = true;
                    break;
                }
            }
            if (!isExist) // 不存在该元素，添加
                nums[index++] = n1[i];
        }
    }
    *returnSize = index;
    return nums;
}

int *intersection_2(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    if (nums1Size == 0 || nums2Size == 0 || !nums1 || !nums2) {
        *returnSize = 0;
        return NULL;
    }
    // 最大的交集不会超过两数组中最小的数组大小
    int min = nums1Size < nums2Size ? nums1Size : nums2Size, index = 0, *n1 = nums1, *n2 = nums2;
    // 这里用 calloc 没用 malloc，因为 calloc 初始化的内存默认值为 0，malloc 初始化的内存默认值随机
    int *nums = calloc(min, sizeof(int)), *hash = calloc(1024, sizeof(int));
    assert(nums != NULL && hash != NULL);
    for (int i = 0; i < nums1Size; hash[*n1++]++, ++i);   // 将值作为下标，并将 hash 表内对应的区域的值增加，也就是非 0 即存在
    for (int j = 0; j < nums2Size; ++j) {
        int position = *n2++;   // 取出数组中的元素值
        if (hash[position]) {   // 当 hash 表中存在改值
            hash[position] = 0; // 置 0，防止添加重复的元素
            nums[index++] = position;   // 将值存到目标数组
        }
    }
    free(hash);
    *returnSize = index;
    return nums;
}

int compare(const void *nums1, const void *nums2) {
    return *(int *) nums1 - *(int *) nums2;
}

int *intersection_3(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    if (nums1Size == 0 || nums2Size == 0 || !nums1 || !nums2) {
        *returnSize = 0;
        return NULL;
    }
    // 两个数组排序
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    // 为目标数组开辟空间
    int *nums = malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size)), index = 0;
    assert(nums != NULL);
    // 归并
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            nums[index] = nums1[i];
            i++, j++;
            // 是第一个元素或者不是第一个元素且当前元素与前一个元素不等
            if (!index || (nums[index - 1] != nums[index]))
                index++;
        }
    }
    // 重新分配合适的空间，这一步可以省略
    nums = realloc(nums, sizeof(int) * index);
    *returnSize = index;
    return nums;
}

void homework_037_349(void) {

}