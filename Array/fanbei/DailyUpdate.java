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

     /**
     * 2020.06.3
     * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
     * 实现 strStr() 函数。
     * <p>
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     * <p>
     * 示例 1:
     * <p>
     * 输入: haystack = "hello", needle = "ll"
     * 输出: 2
     * 示例 2:
     * <p>
     * 输入: haystack = "aaaaa", needle = "bba"
     * 输出: -1
     * 说明:
     * <p>
     * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
     * <p>
     * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     *
     */
    private static int findStringIndex(String haystack, String needle) {
        char[] needFindChar = needle.toCharArray();
        int target = -1;
        if (needle == null || needle.equals("")) {
            return 0;
        }
        for (int i = 0; i <= haystack.length() - needFindChar.length; i++) {
            if (haystack.charAt(i) != needFindChar[0]) {
                while (++i <= haystack.length() && haystack.charAt(i) != needFindChar[0]) ;
            }
            if (i < haystack.length()) {
                int j = i + 1;
                int end = j + needFindChar.length - 1;
                for (int k = 1; j < end && haystack.charAt(j) == needFindChar[k]; k++, j++) ;
                if (j == end) {
                    return i;
                }
            }
        }
        return target;
    }

    /**
     * 2020.06.4
     * 面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
     * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
     * <p>
     * 初始化 A 和 B 的元素数量分别为 m 和 n。
     * <p>
     * 示例:
     * <p>
     * 输入:
     * A = [1,2,3,0,0,0], m = 3
     * B = [2,5,6],       n = 3
     * <p>
     * 输出: [1,2,2,3,5,6]
     * 说明:
     * <p>
     * A.length == n + m
     */
    private int[] onMergeArray(int[] a, int[] b, int m, int n) {
        int i = 0, j = 0, k = a.length - 1, moveA = 0;
        while (i < a.length) {
            if (a[i] <= b[j] && moveA != m) {
                i++;
                moveA++;
            } else {
                while (moveA != m && k > i) {
                    a[k] = a[k - 1];
                    k--;
                }
                a[i++] = b[j++];
                if (j == n) {
                    break;
                }
                k = a.length - 1;
            }
        }
        return a;
    }
}