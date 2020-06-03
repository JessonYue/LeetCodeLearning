/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [70] 爬楼梯
*/

// @lc code=start
class Solution {
   
  public int strStr(String haystack, String needle) {
        int L = haystack.length();
        int R =needle.length();
        for(int i =0;i<L-R+1;i++){
            if(haystack.substring(i,i+R).equals(needle)){
                return R;
            }
        }
        return -1;
    }
}
// @lc code=end