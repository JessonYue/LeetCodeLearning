/**
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorted-merge-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

解题思路，一开始最初的想法有两个，第一，创建一个新的数组，遍历AB两个数组每个位置上对比，按大小排序放入新的数组，再将新的数组赋值给数组A，第二，就是把数组
         B直接放入数组，重新排序，后来结合这两点做了优化，充分利用数组A的大小，由大到小排序即可
**/

class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(m == 0 && n != 0) {
            while(n>0) {
                A[n-1] = B[n-1];
                n--;
            }
            return;
        }

        if (n == 0 && m != 0) {
            return;
        }

        int i=m;
        int j=n;
        int k=m+n-1;


        for(; k>=0; k--) {
            if(A[i-1] > B[j-1]) {
                A[k] = A[i-1];
                i--;

            } else {
                A[k] = B[j-1];
                j--;
            }

            if(i<=0 || j<=0) {
                break;
            }
        }

        if(j>0) {
            //将B数组剩余的放入A
            while(j>0) {
                A[j-1] = B[j-1];
                j--;
            }
        }
    }
}