package com.slow.lib.practice.sort;

import java.util.Arrays;

/**
 * 快速排序
 * 利用快速排序在O(n)的时间查找第k大的元素
 * @Author wuchao
 * @Date 2020/4/25-1:27 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class QuickSort {
    public static void main(String[] args) {
        int[] unSortNums = new int[]{34,435,54,345,7,5,32,1,56,78,23,6,789,0,43,1,2,5,7,2,32,5,234};
        quickSort(unSortNums);
        System.out.println(Arrays.toString(unSortNums));
        System.out.println("top 5 item is:"+quickSortFindTopK(unSortNums,5));
    }

    public static int quickSortFindTopK(int[] nums, int k){
        return quickSortTopK(nums,0,nums.length-1,k-1);
    }

    public static int quickSortTopK(int[] nums, int start, int end, int k){
        if(start>=end){
            return start;
        }
        int p = partition(nums,start,end);
        if(p>k){
            quickSortTopK(nums,start,p-1,k);
        } else if(p<k){
            quickSortTopK(nums,p+1,end,k);
        }
        return nums[k];
    }

    public static void quickSort(int[] nums){
        quickSortPart(nums,0,nums.length-1);
    }

    private static void quickSortPart(int[] a, int m, int n) {
        if(m>=n){
            return;
        }
        int p = partition(a,m,n);
        quickSortPart(a,m,p-1);
        quickSortPart(a,p+1,n);
    }

    private static int partition(int[] a, int start,int end) {
        int i=start,j=start;
        int pivot = a[end];
        while (j<end){
            if(a[j]<pivot){
                if(i!=j){
                    swap(a,i++,j++);
                } else {
                    i++;
                    j++;
                }
            } else {
                j++;
            }
        }
        swap(a,i,j);
        return i;
    }

    private static void swap(int[] a,int b,int c){
        int temp = a[b];
        a[b] = a[c];
        a[c] = temp;
    }


}
