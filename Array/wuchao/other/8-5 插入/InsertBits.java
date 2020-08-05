package com.slow.lib.practice.others;

/**
 * @Author wuchao
 * @Date 2020/8/5-10:50 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class InsertBits {
    //位移运算，但是题目的意思没有表达清楚，没有说明j-i+1大于M位数的情况应该怎么处理，题目的意思是
    //从j位到i位都得替换，塞入M，如果j-i+1大于M的位数，高位补0
    //那么就很简单了，将N的j到i位置成0，然后M左移i位，N|M即是结果
    public int insertBits(int N, int M, int i, int j) {
        int mask = ~(((1<<(j-i+1))-1)<<i);
        N = N&mask;
        M=M<<i;
        return N|M;
    }
}
