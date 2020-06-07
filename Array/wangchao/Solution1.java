class Solution {
    public int strStr(String haystack, String needle) {
        //为了确保程序的稳健型，做一些判断是有必要的
        if(haystack == null )return -1;
        if(needle == null || needle.length() == 0)return 0;
        int l1 = haystack.length();
        int l2 = needle.length();
        int p1 = 0; //haystack的指针
        while(l1 - l2 + 1 > p1){
            
            while(p1 < l1 - l2 + 1 && haystack.charAt(p1) != needle.charAt(0)) ++p1;

            //首个字母相等，开始内循环
            int p2 = 0;
            int curLen = 0;//用于记数当前比较的字符串的长度 
            while(l1 > p1 && l2 > p2 && 
            haystack.charAt(p1) == needle.charAt(p2)){
                ++p1;
                ++p2;
                ++curLen;
            }

            if(curLen == l2) return p1 - curLen;
            // 如果不是完全匹配，需要回溯

            p1 = p1 - curLen + 1;
        }
        // 题目要求返回的是-1，不是0
        return -1;å
    }
}
