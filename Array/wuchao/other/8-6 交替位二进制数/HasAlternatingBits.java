package com.slow.lib.practice.others;

/**
 * 就是将每一位&1，得到的结果用一个flag保存，这一位得到的结果和上一位的结果比较，如果一致则返回false
 * 如果不一致，则继续，直到遍历完所有的位，返回true
 * @Author wuchao
 * @Date 2020/8/6-9:07 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class HasAlternatingBits {
    public boolean hasAlternatingBits(int n) {
        int mask = 1;
        int move=n;
        boolean flag = (move&mask)>0;
        move = move>>>mask;
        while(move!=0){
            int temp = move & mask;
            if(temp>0){
                if(flag) return false;
            } else {
                if(!flag) return false;
            }
            flag = temp>0;
            move = move>>>mask;
        }
        return true;
    }
}
