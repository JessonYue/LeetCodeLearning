package com.company;

/**
 * @description: 70. 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * <p>
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 * @solution: 主要还是在于解题思路，最后的思路是i3=i2+i1，知道这个步骤其它的就是加法操作
 * 1阶：定值1
 * 2阶：1阶 + 2 阶
 * 3阶=2阶+1阶
 * 4阶=3阶+2阶
 * 5阶=4阶+3阶
 */
public class _0602 {
    public static void main(String args[]){
        int n = 10;
        int result = climbingladder(0,n);
        System.out.println("爬梯子的步数："+result);
    }
    /**
     * @param currentLadder 当前所属梯子
     * @param finalLadder   梯子的总高度
     * @return
     */
    static int climbingladder(int currentLadder, int finalLadder) {
        if (currentLadder == finalLadder) {
            return 1;
        } else if (currentLadder > finalLadder) {
            return 0;
        } else {
            return climbingladder(currentLadder + 1, finalLadder) + climbingladder(currentLadder + 2, finalLadder);
        }
    }


}
