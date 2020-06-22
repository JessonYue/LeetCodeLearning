package com.chow;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        int A[] = {5, 4, 0, 3, 1, 6, 2};

        getMaxNestedArray(A);
    }

    //循环遍历，这种解法时间复杂度比较大，明天再想下其他优化解法
    private static void getMaxNestedArray(int array[]){
        List<Integer> resList = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        int length = array.length;
        int res = 0;
        for(int i=0; i<length; i++){
            if(list != null){
                list.clear();
            }
            int tmp = i, count = 1;
            while (array[tmp] != i){
                list.add(tmp);
                tmp = array[tmp];
                count += 1;
            }
            list.add(tmp);
            if(res < count){
                res = count;
                if(resList != null){
                    resList.clear();
                }
                resList.addAll(list);
            }
        }
        System.out.println("嵌套数组最大长度为： " + res);
        printResult(resList, array);
    }

    private static void printResult(List<Integer> list, int[] array){
        StringBuilder resKey = new StringBuilder();
        StringBuilder resValue = new StringBuilder();
        resKey.append('{');
        resValue.append(" = ");
        resValue.append('{');
        int size = list.size();
        for(int i=0; i<size; i++){
            resKey.append(String.format("A[%d]", list.get(i)));
            resValue.append(array[list.get(i)]);
            if(i != size -1){
                resKey.append(", ");
                resValue.append(", ");
            }
        }
        resKey.append('}');
        resValue.append('}');
        resKey.append(resValue.toString());
        System.out.println("其中一种最长的 S[K]:");
        System.out.println("S[0] = " + resKey.toString());
    }
}
