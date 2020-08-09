package com.slow.lib.practice.sort;

import java.util.Arrays;

/**
 * 归并排序
 *
 * @Author wuchao
 * @Date 2020/4/25-11:56 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class MergeSort {
    public static void main(String[] args) {
        int[] unSortNums = new int[]{34,435,54,345,7,5,32,1,56,78,23,6,789,0,43,1,2,5,7,2,32,5,234};
        mergeSort(unSortNums);
        System.out.println(Arrays.toString(unSortNums));
    }

    private static void mergeSort(int[] nums) {
        mergeSortPart(nums, 0, nums.length - 1);
    }

    /**
     * 排序子数组
     *
     * @param a 数组
     * @param b 起始点下标
     * @param c 终止点下标
     * @return
     */
    private static void mergeSortPart(int[] a, int b, int c) {
        if (b >= c) {
            return;
        }
        int middle = (c + b) / 2;
        mergeSortPart(a, b, middle);
        mergeSortPart(a, middle + 1, c);
        merge(a, b, c, middle);
    }

    /**
     * 合并子数组
     * @param a 数组
     * @param start 起始点下标
     * @param end 终结点下标
     * @param middle 中间点下标
     */
    private static void merge(int[] a, int start, int end, int middle) {
        int[] temp = new int[end - start + 1];
        int i = start;
        int j = middle+1;
        int k = 0;
        while (i<=middle&&j<=end) {
            if(a[i] <= a[j]){
                temp[k] = a[i];
                i++;
            } else {
                temp[k] = a[j];
                j++;
            }
            k++;
        }

        while(i<=middle){
            temp[k] = a[i];
            k++;
            i++;
        }
        while(j<=end){
            temp[k] = a[j];
            k++;
            j++;
        }
        int m=start;
        k=0;
        while (m<=end){
            a[m] = temp[k];
            m++;
            k++;
        }
    }
}
