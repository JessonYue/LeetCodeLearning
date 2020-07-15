package com.slow.lib.practice.array;

import java.util.HashMap;
import java.util.LinkedHashMap;

/**
 * @Author wuchao
 * @Date 2020/7/15-10:01 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindUniqChar {
    public int firstUniqChar(String s) {
        int[] count = new int[26];
        for(int i=0;i<s.length();i++){
            count[s.charAt(i) - 'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(count[s.charAt(i) - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
}
