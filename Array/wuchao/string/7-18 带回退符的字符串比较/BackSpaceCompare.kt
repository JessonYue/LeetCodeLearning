package com.slow.lib.practice.string

/**
 * 另一种思路，从字符串尾部开始从前遍历，分别对比两个字符串的字符，如果遇到#则跳过#之前的那个字符
 * 直到遍历完字符串。中间遇到字符不相等即返回false，如果其中一个字符串遍历完而另一个没遍历完还剩不是#的字符也返回false
 * 如果跳过所有#前面的字符后，其他字符都相等，则返回true
 * @Author wuchao
 * @Date 2020/7/18-10:47 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class BackSpaceCompare {
    fun backspaceCompare(S: String, T: String): Boolean {
        var i = S.length - 1
        var j = T.length - 1
        var skipCountS = 0
        var skipCountT = 0
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if(S[i]=='#'){
                    skipCountS++
                    i--
                    continue
                }
                if(skipCountS>0){
                    i--
                    skipCountS--
                    continue
                }
                break
            }
            while(j>=0){
                if(T[j]=='#'){
                    skipCountT++
                    j--
                    continue
                }
                if(skipCountT>0){
                    j--
                    skipCountT--
                    continue
                }
                break
            }
            if(i>=0&&j>=0&&S[i]!=T[j]){
                return false
            }
            if((i-->=0)!=(j-->=0)){
                return false
            }

        }
        return true

    }
}