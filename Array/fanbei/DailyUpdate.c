#include <stdio.h>
#include <stdlib.h>

//编译C/C++的环境还没配置好，没跑测试,后面会把缺失东西都补回来
int main()
{
    printf(get(6));
    return 0;
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
int get(int total)
{
    if (total <= 0)
    {
        return 0;
    }
    if (total == 1)
    {
        return 1;
    }
    if (total == 2)
    {
        return 2;
    }
    return get(total - 1) + get(total - 2);
}