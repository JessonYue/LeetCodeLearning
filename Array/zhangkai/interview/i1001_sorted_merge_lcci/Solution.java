package com.github.leetcode.interview.i1001_sorted_merge_lcci;

import java.util.Arrays;

/**
 * https://leetcode-cn.com/problems/sorted-merge-lcci/
 * <p>
 * 面试题 10.01. 合并排序的数组(这道题目和p0021相似)
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
 * 初始化 A 和 B 的元素数量分别为 m 和 n。
 * <p>
 * 示例：
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * 输出: [1,2,2,3,5,6]
 * <p>
 * 时间复杂度在 O(n^2)
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    /*public void merge(int[] A, int m, int[] B, int n) {
        //将 B 合并入 A
        for (int i = m; i < m + n; i++) {
            A[i] = B[i - m];
        }
        //System.out.println(Arrays.toString(A));
        //对A数组进行排序（冒泡、选择、插入；快速、归并、Shell）这里选择冒泡
        for (int i = 0; i < A.length - 1; i++) {
            for (int j = 0; j < A.length - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    swap(A, j, j + 1);
                }
            }
        }
        System.out.println(Arrays.toString(A));
    }*/

    //另一种思路：使用直接使用插入排序，A为有序数组，B为待插入数组(待完善)
    public void merge(int[] A, int m, int[] B, int n) {
        //将 B 合并入 A
        for (int i = m; i < m + n; i++) {
            A[i] = B[i - m];
        }
        //插入排序，从A数组m位置到m+n-1位置为对比对象
        //1, 7, 15, 2, 5, 6, 8
        //1, 7, 2, 15, 5, 6, 8

        System.out.println(Arrays.toString(A));
    }

    private void swap(int[] a, int j, int i) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] A = {1, 7, 15, 0, 0, 0, 0};
        int[] B = {2, 5, 6, 8};
        solution.merge(A, 3, B, 4);
    }

    /**
     * --------------------别人的代码--------------------
     */

}