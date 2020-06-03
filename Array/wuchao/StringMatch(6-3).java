class Solution {
    //leetcode 28
    //暴力匹配法，即一位一位的比较，不会用KMP算法...
    public int strStr(String haystack, String needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length()<needle.length()){
            return -1;
        }
        char[] haystackChars = haystack.toCharArray();
        char[] needleChars = needle.toCharArray();
        for(int i=0;i<haystackChars.length;i++){
            int j = 0;
            for(;j<needleChars.length;j++){
                if(i+j>=haystackChars.length){
                    return -1;
                }
                if(haystackChars[i+j]==needleChars[j]){
                    continue;
                } else {
                    j=-1;
                    break;
                }
            }
            if(j==needleChars.length){
                return i;
            }
        }
        return -1;
    }
}
