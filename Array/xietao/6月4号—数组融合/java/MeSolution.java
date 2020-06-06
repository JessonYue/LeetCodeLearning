public class MeSolution {
        public void merge(int[] A, int m, int[] B, int n) {
            for(int i = 0; i<n;i++){
                int b = B[i];
                int j = m - 1 + i;
                while(j >= 0 && b <= A[j]){
                    A[j+1] = A[j];
                    j--;
                }
                A[j+1] = b;
            }
        }
    }


