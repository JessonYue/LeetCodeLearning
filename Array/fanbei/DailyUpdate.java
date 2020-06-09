package com.example.coordinatorlayoutdemo;

import org.junit.Test;
import static org.junit.Assert.*;


public class ExampleUnitTest {
    // @Test
    // public void addition_isCorrect() {
        
    //     //第一天的暂时没想法，后面会补上.
    //     ClimbStairs climbStairs = new ClimbStairs();//第二天(0602)
    //     System.out.println(climbStairs.get(6));

    // }

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

    /**
     *
     * @param array 数组
     * @param target 目标值
     * @return
     */
    private int[] fetchingArrayIndex(int[] array,int target) {

        int[] defaultValue ={-1,-1};

        for (int i=0;i<array.length-1;i++) {
            for (int j=i+1;j<array.length;j++){
                 if(array[i]+array[j]==target){
                      defaultValue[0] = array[i];
                      defaultValue[1] = array[j];
                      break;
                 }
            }
        }
        return defaultValue;
    }

    /**
     * 2020.06.2
     * 70. 爬楼梯
     * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
     *
     * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
     *
     * 注意：给定 n 是一个正整数。
     *
     * 示例 1：
     *
     * 输入： 2
     * 输出： 2
     * 解释： 有两种方法可以爬到楼顶。
     * 1.  1 阶 + 1 阶
     * 2.  2 阶
     * 示例 2：
     *
     * 输入： 3
     * 输出： 3
     * 解释： 有三种方法可以爬到楼顶。
     * 1.  1 阶 + 1 阶 + 1 阶
     * 2.  1 阶 + 2 阶
     * 3.  2 阶 + 1 阶
     */
    public class ClimbStairs {
        private int get(int total) {
            if (total <= 0) {
                return 0;
            }
            if (total == 1) {
                return 1;
            }
            if (total == 2) {
                return 2;
            }
            return get(total - 1)  + get(total - 2);
        }
    }


}