package com.chow;

/**
 * 大小为 K 且平均值大于等于阈值的子数组数目
 */
public class Main {

    public static void main(String[] args) {
	    // write your code here
//        int arr[] = {2, 2, 2, 2, 5, 5, 5, 8};
//        int k = 3, threshold = 4;

//        int arr[] = {1, 1, 1, 1, 1};
//        int k = 1, threshold = 0;

//        int arr[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
//        int k = 3, threshold = 5;

//        int arr[] = {7,7,7,7,7,7,7};
//        int k = 7, threshold = 7;

        int arr[] = {4, 4, 4, 4};
        int k = 4, threshold = 1;
        getSubArray(arr, k, threshold);

    }

    private static void getSubArray(int array[], int k, int threshold){
        int count = 0;
        int length = array.length;
        int tmp[] = new int[k];
        for(int i=0; i<length-k+1; i++){
            for(int j=0; j<k; j++){
                tmp[j] = array[i+j];
            }
            if(getAvgValue(tmp, k) >= threshold){
                count++;
            }
        }
        System.out.println(String.format("子数组数目len= %d", count));
    }

    private static int getAvgValue(int tmp[], int k){
        int len = tmp.length;
        int sum = 0;
        for(int i=0; i<len; i++){
            sum += tmp[i];
        }
        int avg = sum / k;
        return avg;
    }
}
