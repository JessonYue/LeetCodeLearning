package com.example.coordinatorlayoutdemo;

import org.junit.Test;
import static org.junit.Assert.*;


public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        
        //第一天的暂时没想法，后面会补上.
        ClimbStairs climbStairs = new ClimbStairs();//第二天(0602)
        System.out.println(climbStairs.get(6));

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