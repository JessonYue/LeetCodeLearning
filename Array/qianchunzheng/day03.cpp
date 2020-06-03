//
// Created by qianchunzheng on 2020/6/3.
//
#include <iostream>
using namespace std;


/**
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack
 * 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 * 示例 1:
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 示例 2:
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 说明:
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */



/**
 * 思路：
 * 获取到目标字符串的长度 length
 * 遍历haystack，每次获取length长度的字符串和目标字符串进行比较
 */

class Test{
public:
    int getIndex(string haystack,string needle){
        //若needle是空的返回0
        if(needle.empty()){
            return 0;
        }
        //获取目标字符串长度
        int len = needle.length();
        //遍历字符串
        for (int i = 0; i < haystack.length(); ++i) {
            //判断若i+len 大于haystack的长度，则可以肯定haystack不包含needle
            if((i+len)<= haystack.length()){
                string ss =haystack.substr(i,len);
                if(needle == ss){

                    return i;
                }
            }

        }

        return -1;
    }


};

int main(){
    string haystack = "hello";
    string needle = "ll";

    Test test;
    int i =test.getIndex(haystack,needle);
    cout<<i<<endl;
}

