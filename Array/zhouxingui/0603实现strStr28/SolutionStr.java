
public class SolutionStr {
    public int strStr(String haystack, String needle) {
        int l = haystack.length();
        int n = needle.length();
        for(int start = 0; start < l - n+1;++start){
            if(haystack.substring(start, start + l).equals(needle)){
                return start;
            }
        }
        return -1;
    }
}