package com.slow.lib.practice.array;

/**
 * @Author wuchao
 * @Date 2020/7/16-9:19 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ConvertToHex {
    public String toHex(int num) {
        char[] chars = new char[]{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int mask = 15;
        StringBuilder stringBuilder = new StringBuilder();
        for(int i=0;i<8;i++){
            int bit = num&mask;
            num = num >>>4;
            if(num==0){
                if(bit>0){
                    stringBuilder.append(chars[bit]);
                }
            } else {
                stringBuilder.append(chars[bit]);
            }
        }
        return stringBuilder.reverse().toString();
    }
}
