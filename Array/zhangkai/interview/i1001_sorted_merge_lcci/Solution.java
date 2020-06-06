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
    //一、这种思路是：合并完之后进行全局冒泡排序:6 ms	39.9 MB
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

    //二、这种思路是：合并之后，使用直接使用插入排序，A为有序数组，B为待插入数组(待完善)：3 ms	39.2 MB
   /* public void merge(int[] A, int m, int[] B, int n) {
        //将 B 合并入 A
        for (int i = m; i < m + n; i++) {
            A[i] = B[i - m];
        }
        //插入排序，从A数组m位置到m+n-1位置为对比对象
        //1, 7, 15, 2, 5, 6, 8
        for (int i = m; i < A.length; i++) {
            for (int j = i; j > 0; j--) {
                //比较索引j和索引j-1的值，如果j-1处的值更大，则交换
                if (A[j - 1] > A[j]) {
                    swap(A, j, j - 1);
                } else {
                    break;//这一句很重要！！！用作优化，不用继续往下面比较了
                }
            }
        }
        //System.out.println(Arrays.toString(A));
    }*/


    //三、使用归并排序,需要额外的数组:0 ms	39.9 MB
    int[] assist;

    /*public void merge(int[] A, int m, int[] B, int n) {
        //将 B 合并入 A
        for (int i = m; i < m + n; i++) {
            A[i] = B[i - m];
        }
        assist = new int[A.length + B.length];
        sort(A, 0, A.length - 1);
        //System.out.println(Arrays.toString(A));
    }*/

    private void sort(int[] A, int low, int high) {
        if (low >= high)
            return;
        //分组
        int mid = low + (high - low) / 2;
        //分别对每一组数据进行排序
        sort(A, low, mid);
        sort(A, mid + 1, high);
        //再把两组中的数据进行合并
        merge(A, low, mid, high);
    }


    private void merge(int[] a, int low, int mid, int high) {
        //1. 定义三个指针
        int i = low;
        int p1 = low;
        int p2 = mid + 1;
        //2. 循环遍历
        while (p1 <= mid && p2 <= high) {
            if (a[p1] < a[p2]) {
                assist[i++] = a[p1++];
            } else {
                assist[i++] = a[p2++];
            }
        }

        //3. 将没走完的数据填充到辅助数组中,下面连个while循环只会走一个
        while (p1 <= mid) {
            assist[i++] = a[p1++];
        }
        while (p2 <= high) {
            assist[i++] = a[p2++];
        }
        //4. 把辅助数组中的元素拷贝到原数组
        for (int j = low; j <= high; j++) {
            a[j] = assist[j];
        }
    }


    private void swap(int[] a, int j, int i) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] A = {5, 6, 19, 0, 0, 0};
        int[] B = {2, 5, 6};
        solution.merge(A, 3, B, 3);
        System.out.println(Arrays.toString(A));
    }

    /**
     * --------------------别人的代码--------------------
     */
    //四、O(N)算法
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1, j = n - 1, idx = m + n - 1;
        while (j >= 0) {
            if (i < 0 || B[j] >= A[i]) {
                A[idx--] = B[j--];
            } else {
                A[idx--] = A[i--];
            }
        }
    }
}