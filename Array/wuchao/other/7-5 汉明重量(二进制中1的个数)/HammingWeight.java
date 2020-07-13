package com.slow.lib.practice.others;

/**
 * 求汉明重量(二进制表达式中1的个数)
 * 思路是将这个数和1 求 & ，结果为0的话，最低位就不是1；如果为1的话，最低位就为1。用一个变量累积这个值
 * 然后这个数无符号右移一位，继续求最低位是不是1，这样循环下去，直到这个数变为0
 * 注意是无符号右移，不能是>>，因为>>是有符号右移，如果这个数是负数，最高位为1，有符号右移，最高位符号位不会变动，处理过后的数永远不可能为0，循环无法退出
 * @Author wuchao
 * @Date 2020/7/5-10:41 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class HammingWeight {
    public int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            count+=n&1;
            n = n>>>1;
        }
        return count;
    }
}
