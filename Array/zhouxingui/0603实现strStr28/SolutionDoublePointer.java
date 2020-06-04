public class Solution {
    public int strStr(String haystack, String needle) {
      int L = needle.length(), n = haystack.length();
      if (L == 0) return 0;
  
      int pn = 0;
      while (pn < n - L + 1) {
        // find the position of the first needle character
        // in the haystack string
        while (pn < n - L + 1 && haystack.charAt(pn) != needle.charAt(0)) ++pn;
  
        // compute the max match string
        int currLen = 0, pL = 0;
        while (pL < L && pn < n && haystack.charAt(pn) == needle.charAt(pL)) {
          ++pn;
          ++pL;
          ++currLen;
        }
  
        // if the whole needle string is found,
        // return its start position
        if (currLen == L) return pn - L;
  
        // otherwise, backtrack
        pn = pn - currLen + 1;
      }
      return -1;
    }
  }
  
//   作者：LeetCode
//   链接：https://leetcode-cn.com/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode/
//   来源：力扣（LeetCode）
//   著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。