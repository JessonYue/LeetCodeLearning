public class AnswerSolution {
    public int strStr(String haystack, String needle) {
        int L = needle.length(), n = haystack.length();
        if(L == 0){
            return 0;
        }
        int pn = 0;//这个是haystack字符串的指针
        while(pn < n - L + 1){
            while(pn < n - L +1 && haystack.charAt(pn) != needle.charAt(0)) ++pn;//找到起始的位置
            int currLen = 0;//匹配到相同字符串的长度
            int pL =0;//这是needle字符串的指针
            while(pL < L && pn < n && haystack.charAt(pn)==needle.charAt(pL)){
                ++pn;
                ++pL;
                ++currLen;
            }
            if(currLen == L){
                return pn - L;
            }
            pn = pn - currLen + 1;
        }
        return -1;
    }
}
