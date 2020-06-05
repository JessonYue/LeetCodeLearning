//这种是我自己的解法，三个for循环
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
            //将每一位替换掉
            for(int j = 0;j < n ;j++){
                 A[m+n-j-1] = B[j];
            }
            //冒泡排序
            int temp = 0;
            for(int i = 0;i< A.length-1;i++){
                for(int j = i+1;j < A.length;j++){
                    if(A[i] > A[j]){
                        temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;
                    }
                }
            }
        
    }
}

//参考答案：
    