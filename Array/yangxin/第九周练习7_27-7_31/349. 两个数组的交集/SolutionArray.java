package com.example.admin.myapplication.array;

/**
 * create by yx
 * on 2020/6/22
 */
public class SolutionArray {
 

    /**
     * 349. 两个数组的交集
     * 给定两个数组，编写一个函数来计算它们的交集。
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 ) {
            return nums1;
        }

        if (nums2.length == 0) {
            return nums2;
        }

        insertSort(nums1);
        insertSort(nums2);
        int[] array = new int[Math.min(nums1.length, nums2.length)];
        int count = 0;
        int index = 0;
        if (nums1.length < nums2.length) {
            for (int i = 0; i < nums1.length; i++) {
                for (int j = index; j < nums2.length; j++) {
                    if (nums1[i] == nums2[j]) {
                        if (count == 0 || nums1[i] != array[count - 1]) {
                            array[count++] = nums1[i];
                        }
                        index = j;
                        break;
                    }
                }
            }
        } else {
            for (int i = 0; i < nums2.length; i++) {
                for (int j = index; j < nums1.length; j++) {
                    if (nums2[i] == nums1[j]) {
                        if (count == 0 || nums2[i] != array[count - 1]) {
                            array[count++] = nums2[i];
                        }
                        index = j;
                        break;
                    }
                }
            }
        }
        int[] r = new int[count];
        for (int i = 0; i< count; i++) {
            r[i] = array[i];
        }
        return r;
    }

    //插入排序
    public void insertSort(int[] nums) {
        int current = 0;
        int tmp;
        for (int i = 0; i < nums.length; i++) {
            current = i;
            while (current > 0 && nums[current] < nums[current - 1]) {
                tmp = nums[current - 1];
                nums[current - 1] = nums[current];
                nums[current] = tmp;
                current--;
            }
        }
    }


}
