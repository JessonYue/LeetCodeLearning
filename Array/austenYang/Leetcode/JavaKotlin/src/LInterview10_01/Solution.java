package LInterview10_01;

public class Solution {

    /**
     * 合并后排序
     * @param A
     * @param m
     * @param B
     * @param n
     */
    // A.length == m + n
    public static void merge1(int[] A, int m, int[] B, int n) {
        for (int i = m; i < A.length; i++) {
            A[i] = B[i - m];
        }
        for (int i = 1; i < A.length; i++) {
            for (int j = i; j > 0; j--) {
                if (A[j - 1] > A[j]) {
                    int temp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = temp;
                }
            }
        }
    }


    public static void main(String[] args) {
        int[] A = {1, 2, 3, 0, 0, 0};
        int[] B = {2, 5, 6};
        merge1(A, 3, B, 3);
        for (Integer a :
                A) {
            System.out.print(a + " ");
        }
    }
}
