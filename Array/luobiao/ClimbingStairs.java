/**

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
通过次数197,174提交次数4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/



class Solution {
    public int climbStairs(int n) {
        // return climbStairs(0, n);
        // return f(n);

        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }

    private int climbStairs(int index, int n) {

        if(index > n) {
            return 0;
        }

        if (index == n) {
            return 1;
        }
        
        return climbStairs(index + 1, n) + climbStairs(index + 2, n);
    }

    //根据斐波那契数列fibonacciSequence
    

    private int fn(int n) {
        if(n == 0) {
            return 0;
        }

        if(n==1) {
            return 1;
        }

        if(n==2) {
            return 2;
        }

        return fn(n-1) + fn(n-2);
    }

    private int f(int n){
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;

    }
}