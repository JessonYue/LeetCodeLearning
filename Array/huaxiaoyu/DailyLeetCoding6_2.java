package com.example.myapplication;

import org.junit.Test;

public class DailyLeetCoding6_2 {
    //70. 爬楼梯
    //假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    //每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    //注意：给定 n 是一个正整数。
    //示例 1：
    //输入： 2
    //输出： 2
    //解释： 有两种方法可以爬到楼顶。
    //1.  1 阶 + 1 阶
    //2.  2 阶
    //示例 2：

    //输入： 3
    //输出： 3
    //解释： 有三种方法可以爬到楼顶。
    //1.  1 阶 + 1 阶 + 1 阶
    //2.  1 阶 + 2 阶
    //3.  2 阶 + 1 阶
    @Test
    public void main() {
        System.out.println(recursion(46));
        System.out.println(climb(46));
    }

    //递归1
    public double recursion(double n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return recursion(n - 1) + recursion(n - 2);
    }

    //循环
    public double climb(int n) {
        double[] step = new double[n + 1];
        step[0] = 1;
        step[1] = 2;
        for (int i = 2; i <= n; i++) {
            step[i] = step[i - 1] + step[i - 2];
        }
        return step[n - 1];
    }
}
