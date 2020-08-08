package com.lanfairy.md.eight;

import java.util.LinkedList;

public class sort {

    //冒泡排序
    public static void bubbleSort(int[] array) {
        //3 1 5 8 2 9 4 6 7    n*(n-1)/2    n
        for (int i = array.length - 1; i > 0; i--) {
            boolean flag = true;
            for (int j = 0; j < i; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
    }

    //选择排序
    public static void selectSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[index]) {
                    index = j;
                }
            }
            //{1,2,5,8,3,9,4,6,7};
            if (index != i) {//如果已经是最小的，就不需要交换
                int temp = array[index];
                array[index] = array[i];
                array[i] = temp;
            }
        }
    }

    //直接插入排序
    public static void insertSort(int[] array){
        for (int i = 1; i < array.length; i++) {
            int j=i;
            int target=array[j];
            while(j>0 && target<array[j-1]){
                array[j]=array[j-1];
                j--;
            }
            array[j]=target;
        }
    }

    //希尔排序
    public static void shellSort(int[] array,int step){
        for(int k=0;k<step;k++) {
            //直接插入排序
            for (int i = k + step; i < array.length; i = i + step) {
                int j = i;
                int target = array[j];
                while (j > step - 1 && target < array[j - step]) {
                    array[j] = array[j - step];
                    j = j - step;
                }
                array[j] = target;
            }
        }
    }

    //

}


