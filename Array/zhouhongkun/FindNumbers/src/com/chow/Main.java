package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        int[] array = {12, 345, 2, 6, 7896, 869536, 201};
        findEvenNumber(array);
    }

    private static void findEvenNumber(int[] array){
        int length = array.length;
        int count = 0;
        for(int i=0; i<length; i++){
            int value = array[i];
            if(isEvenNumber(value)){
                count++;
            }
        }
        System.out.println(count);
    }

    //除10判断是否为偶数
    private static boolean isEvenNumber(int value){
        int index = 0;
        while(value / 10 != 0){
            value = value / 10;
            index++;
        }
        if(value % 10 != 0){
            index++;
        }

        if(index % 2 == 0){
            return true;
        }
        return false;
    }
}
