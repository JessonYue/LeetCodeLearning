package com.slow.lib.practice.others;

/**
 * 位运算 数字&15得到最低4位，即是16进制字符数组的下标
 * @Author wuchao
 * @Date 2020/8/4-9:00 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class IntegerToHex {
    public String toHex(int num) {
        char[] chars = new char[]{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int count = 0;
        StringBuilder result = new StringBuilder();
        while(count<8){
            int hex = num&15;
            result.append(chars[hex]);
            num = num>>>4;
            if(num==0) break;
            count++;
        }
        return result.reverse().toString();
    }
}
