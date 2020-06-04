import static java.util.Arrays.sort;
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
	for(int i = 0;i<n;i++){
            A[m+i]=B[i];
        }
        sort(A);
    }
}