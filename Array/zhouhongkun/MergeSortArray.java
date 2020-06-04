package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        int A[] = {0, 8, 12, 27, 54, 0, 0, 0};
        int B[] = {0, 43, 98};
        int m = 5, n = 3;

		//先把B数组里的数据合并到数组A中
        for(int i=m, j=0; i<m + n; i++, j++){
            A[i] = B[j];
        }

		//对合并后的数组A进行排序
        for(int j=0; j< m+n; j++){
            for(int k=j+1; k<m+n; k++){
                if(A[j] > A[k]){
                    int temp = A[j];
                    A[j] = A[k];
                    A[k] = temp;
                }
            }
        }

		//打印输入合并排序后的数组A
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append('[');
        for(int i=0; i<m + n; i++){
            stringBuilder.append(A[i]);
            if(i != m+n-1){
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append(']');
        System.out.println(stringBuilder.toString());
    }
}
