package com.slow.lib.practice.string;

/**
 * 头尾指针，一开始指向头尾两个字符，交换两个字符的位置，然后头指针前进一步，尾指针后退一步
 * 直到头指针大于等于尾指针
 * @Author wuchao
 * @Date 2020/7/6-10:09 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ReverseString {
    public void reverseString(char[] s) {
        int start = 0, end = s.length -1;
        while(start<end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
}
