package com.moneycz.jianzhioffer.algorithm;

import org.junit.Test;

import java.util.ArrayList;

/**
 * 2020.06.1
 * 167. 两数之和 II - 输入有序数组
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 说明:
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 示例:
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [0,1]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2。
 */
public class Day01 {
    @Test
    public void run() {
        int [] array = {2, 7, 11, 15};
        int target = 9;
        int[] arrayIndex = getArrayIndex(array, target);
        System.out.println(arrayIndex[0]+","+arrayIndex[1]);
    }

    /**
     * 思路：
     * 既然是有序数组，那么数组中的值必定是按照从小到大排列。
     * 那么我们可以从首位两端取值相加与目标值对比：
     *  若大于目标值，则尾部的下标向前移动一位。之所以尾部下标向前移动一位，
     *  是因为数组是从小到大排列的，尾部下标向前移动一位然后再取值相加得到
     *  的和肯定比之前的和小，此时再去和目标值比较。
     *  若小于目标值，则头部下标向前移动一位，再取值相加，此时得到的和肯定
     *  比之前得到的和大，再去比较。
     *  不断循环上面两步，直到去到目标值
     * @param array  有序数组
     * @param target 目标值
     * @return
     */
    public int[] getArrayIndex(int [] array,int target){
        //取头部下标
        int i = 0;
        //取尾部下标
        int j = array.length-1;
        while (i<j){
            if(array[i]+array[j]>target){
                j--;
            }else if (array[i]+array[j]<target){
                i++;
            }else {
                return new int[]{i,j};
            }
        }
        return new int[]{-1,-1};
    }

}
