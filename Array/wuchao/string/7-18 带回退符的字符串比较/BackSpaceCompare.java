package com.slow.lib.practice.string;

/**
 * 取两个字符串的字符数组，用一个stackTopIndex 指向栈顶，在字符串数组上模拟栈的操作。
 * 遍历字符串数组，如果不是#则stackTopIndex++，并且将这个字符赋值为chars[i]的值，代表入栈
 * 如果字符为#则stackTopIndex--，代表出栈。遍历完之后则两个字符数组后，栈里面放的都是去除退格字符后的字符。
 * 最后对比两个字符数组的栈，栈容量不等返回false，所有元素都相等返回true
 * @Author wuchao
 * @Date 2020/7/18-10:47 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class BackSpaceCompare {
    public boolean backspaceCompare(String S, String T) {
        char[] sChars = S.toCharArray();
        char[] tChars = T.toCharArray();
        int stackTopS = -1,stackTopT = -1;
        for(int i=0;i<sChars.length;i++){
            if(sChars[i]!='#'){
                sChars[++stackTopS] = sChars[i];
            } else {
                if(stackTopS==-1) continue;
                stackTopS--;
            }
        }
        for(int i=0;i<tChars.length;i++){
            if(tChars[i]!='#'){
                tChars[++stackTopT] = tChars[i];
            } else {
                if(stackTopT==-1) continue;
                stackTopT--;
            }
        }
        if(stackTopT!=stackTopS) return false;
        if(stackTopS==-1&&stackTopT==-1) return true;
        for(int i=0;i<=stackTopS;i++){
            if(sChars[i]!=tChars[i]){
                return false;
            }
        }
        return true;
    }
}
