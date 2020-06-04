class Solution {
    public void merge(int[] A, int m, int[] B, int n) {

        if(A == null || B == null || A.length < B.length) {
            return;
        }
        int index = m + n - 1; // A数组最末一个可被替换元素的下标
        int aIndex = m - 1; // A数组剩下元素的个数最末元素的下标
        int bIndex = n - 1; // B数组剩下元素的个数最末元素的下标

        for(int i = index; i >= 0; i--) {
                if(aIndex < 0) { // 这里证明只剩下B数组有元素了
                    A[i] = B[bIndex--];
                    continue;
                }
                if(bIndex < 0) { // 这里证明只剩下A数组有元素了
                    A[i] = A[aIndex--];
                    continue;
                }

                if(A[aIndex] > B[bIndex]) { // 把两个数组最末的两个元素的最大值，放在i处，然后--
                    A[i] = A[aIndex--];
                } else {
                    A[i] = B[bIndex--];
                }
        }

    } 
}