/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [70] 爬楼梯
*/

// @lc code=start
class Solution {
   
 /**
 * 思路，把B数组的数字放入A数组
 **/
 public static void merge(int[] A, int m, int[] B, int n) {
        while (m > 0 && n > 0) {
            A[m + n - 1] = A[m - 1] > B[n - 1] ? A[m-- - 1] : B[n-- - 1];
        }
        while (n > 0) {
            A[n - 1] = B[n - 1];
            n--;
        }
    }
}
// @lc code=end