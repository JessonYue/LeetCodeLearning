package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding6_4 {
    //2020.06.4
    //合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
    //给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
    //初始化 A 和 B 的元素数量分别为 m 和 n。
    //示例:
    //输入:
    //A = [1,2,3,0,0,0], m = 3
    //B = [2,5,6],       n = 3
    //输出: [1,2,2,3,5,6]
    //说明:
    //A.length == n + m
    @Test
    public void test() {
        int[] result = sort(new int[]{2, 0}, 1, new int[]{1}, 1);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }

    /**
     * 思路
     * 0. 创建两个指针
     * 1. 找到a1中的最大的下标
     * 2. 为了节省空间,直接利用a1做容器
     * 3. 从a1的后方排最大的值,若a1大 a2指针-- , 将a1的最后一个放到后面, 反之将a2放到后面,a1--
     */
    public int[] sort(int[] A, int m, int[] B, int n) {
        int max = m == 0 ? 0 : m - 1;
        int j = n - 1;
        for (int k = A.length - 1; max >= 0 && k >= 0 && j >= 0; ) {
            if (B[j] > A[max]) {
                A[k] = B[j];
                j--;
            } else {
                A[k] = A[max];
                max--;
            }
            k--;
        }
        if (j >= 0) {
            for (int i = 0; i <= j; i++) {
                A[i] = B[j];
            }
        }
        return A;
    }
}
