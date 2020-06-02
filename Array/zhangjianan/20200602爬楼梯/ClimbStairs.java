package com.test;

public class ClimbStairs {
    public static void main(String[] args) {
        int n=20;
        int i=0;
        System.out.println(climbStairs(i,n));
        System.out.println(climbStairs1(i,n,new int[n+1]));
    }

    private static int  climbStairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return  climbStairs(i+1,n)+climbStairs(i+2,n);
    }
    public static int climbStairs1(int i,int n,int memo[]){
        if (i > n) {
            return 0;
        }
        if (i==n) {
            return 1;
        }
        if (memo[i]>0) {
            return memo[i];
        }
        memo[i] = climbStairs1(i + 1, n, memo) + climbStairs1(i + 2, n, memo);
        return memo[i];
    }
}
