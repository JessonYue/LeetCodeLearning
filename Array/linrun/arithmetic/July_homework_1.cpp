//
// Created by Administrator on 2020/7/16.
//

//课后作业
//· https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
//26. 删除排序数组中的重复项
//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
int removeDuplicates(int* nums, int numsSize){
    int slow = 0;
    int fast = 1;
    int count = 1;
    int curNum = nums[0];
    for(int i =0; i<numsSize -1; i++){
        if(nums[i +1] != nums[i] ){
            nums[count]= nums[i+1];
            count++;
        }
    }
    return count;
}

//· https://leetcode-cn.com/problems/rotate-array/
//189. 旋转数组
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//示例 1:
//输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]

void rotate(int* nums, int numsSize, int k){
    int time =0;
    while(time < k){
        int temp = nums[0];
        int temp2;
        int target;
        for(int i =0; i<numsSize; i++){
            target = (i+1)%numsSize;
            temp2 = nums[target];
            nums[target] = temp;
            temp = temp2;
        }
        time++;
    }
}

//· https://leetcode-cn.com/problems/merge-two-sorted-lists/
//21. 合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* firstNode = NULL;
    struct ListNode* pre = NULL;
    struct ListNode* small = NULL;
    while(l1 && l2){
        if(l1->val < l2->val){
            small = l1;
            l1 = l1->next;
        }else{
            small = l2;
            l2 = l2->next;
        }
        if(pre){
            pre->next = small;
        }
        pre = small;
        if(!firstNode){
            firstNode = small;
        }
    }
    while(l1){
        small = l1;
        l1 = l1->next;
        if(pre){
            pre->next = small;
        }
        pre = small;
        if(!firstNode){
            firstNode = small;
        }
    }
    while(l2){
        small = l2;
        l2 = l2->next;
        if(pre){
            pre->next = small;
        }
        pre = small;
        if(!firstNode){
            firstNode = small;
        }
    }
    return firstNode;

}


//· https://leetcode-cn.com/problems/merge-sorted-array/
//88. 合并两个有序数组
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//说明:

//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

//示例:
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3

//输出: [1,2,2,3,5,6]

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int size1 = m;
    int size2 = n;
    while(size1 && size2){
        if(nums1[size1 -1] > nums2[size2 -1]){
            nums1[size2 + size1 -1] = nums1[size1 -1];
            size1--;
        }else{
            nums1[size2 + size1 -1] = nums2[size2 -1];
            size2--;
        }
    }
    while(size2){
        nums1[size2 -1] = nums2[size2 -1];
        size2--;
    }
}

//· https://leetcode-cn.com/problems/two-sum/
//1. 两数之和
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    for(int i=numsSize -1; i>0; i--){
        bool hasChange = false;
        int temp;
        for(int j=0; j<i; j++){
            if(nums[j+1] < nums[j]){
                hasChange = true;
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
        if(!hasChange){
            break;
        }
    }

    int low = 0;
    int high = numsSize -1;
    while(high>low){
        if(nums[low] + nums[high] > target){
            high--;
        }else if(nums[low] + nums[high] < target){
            low++;
        }else{
            int* p = (int*)malloc(sizeof(int) * 2);
            *returnSize = 2;
            p[0] = low;
            p[1] = high;
            return p;
        }
    }
    return NULL;
}


//· https://leetcode-cn.com/problems/move-zeroes/

//283. 移动零
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//示例:

//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
void moveZeroes(int* nums, int numsSize){
    int lastZeroIndex = numsSize -1;
    for(int i=numsSize -1; i>=0; i--){
        if(nums[i] == 0){
            for(int start =i; start<lastZeroIndex; start++){
                nums[start] = nums[start+1];
            }
            nums[lastZeroIndex] =0;
            lastZeroIndex --;
        }
    }
}



//· https://leetcode-cn.com/problems/plus-one/
//66. 加一
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

//你可以假设除了整数 0 之外，这个整数不会以零开头。

//示例 1:

//输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize -1; i>=0; i--){
        if(digits[i] == 9){
            digits[i] = 0;
            if(!i){
                int* result = (int*)malloc(sizeof(int)*(digitsSize+1));
                result[0] =1;
                for(int j=0; j<digitsSize; j++){
                    result[j+1] = digits[j];
                }
                *returnSize = digitsSize+1;
                return result;
            }
        }else{
            digits[i] = digits[i] + 1;
            break;
        }

    }
    *returnSize = digitsSize;
    return digits;

}