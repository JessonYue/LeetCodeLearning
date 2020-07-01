package com.chow;

public class Main {

    public static void main(String[] args) {
        // write your code here
//        int array[] = {1, 2, 3, 4, 5};
//        int array[] = {3, 3, 5, 0, 0, 3, 1, 4};
        int array[] = {7, 6, 4, 3, 1};
        System.out.println(getMaxProfit(array));
    }

    private static int getMaxProfit(int array[]){
        if(array == null || array.length == 0){
            return 0;
        }
        int length = array.length;
        int leftMaxArray[] = new int[length];
        int rightMaxArray[] = new int[length];
        int leftMin = array[0];
        for(int i=1; i<length; i++){
            if(array[i] < leftMin){
                leftMin = array[i];
            }
            leftMaxArray[i] = Math.max(leftMaxArray[i], array[i] - leftMin);
        }
        int rightMax = array[length-1];
        for(int i=length-2; i>=0; i--){
            if(array[i] > rightMax){
                rightMax = array[i];
            }
            rightMaxArray[i] = Math.max(rightMaxArray[i+1], rightMax - array[i]);
        }
        int res = 0;
        for(int i=0; i<length; i++){
            res = Math.max(res, leftMaxArray[i] + rightMaxArray[i]);
        }
        return res;
    }
}
