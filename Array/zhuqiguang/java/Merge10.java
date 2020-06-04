/**
 * 2020.06.4
 * 面试题 10.01. 合并排序的数组 //https://leetcode-cn.com/problems/sorted-merge-lcci/
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
 * <p>
 * 初始化 A 和 B 的元素数量分别为 m 和 n。
 * <p>
 * 示例:
 * <p>
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * <p>
 * 输出: [1,2,2,3,5,6]
 * 说明:
 * <p>
 * A.length == n + m
 */
public class Merge10 {
    public static void main(String[] args) {

    }

    /**
     * 解题思路：
     * 开辟新的临时数组tmp,
     * 分别为原有两个数组的最后一个index设置指针i和j,
     * 如果A[i]<B[j],那么就把A[j]放到tmp，反之，则把A[i]放到tmp，这叫做双指针解法
     */
    public void merge(int[] A, int m, int[] B, int n) {
        int k = m + n + 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] < B[j]) {
                A[k--] = B[j--];
            } else {
                A[k--] = A[i--];
            }
        }
        //TODO 这里不太明白
        while (j >= 0) A[k--] = B[j--];
    }
}


