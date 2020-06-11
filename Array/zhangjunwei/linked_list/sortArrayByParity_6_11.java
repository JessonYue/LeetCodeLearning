package com.lanfairy.md;


import java.util.Arrays;
import java.util.Comparator;
import java.util.function.IntFunction;
import java.util.function.ToIntFunction;

public class sortArrayByParity {
    public static void main(String[] args) {
        int[] A = new int[]{3,1,2,4};

        sortArrayByParity(A);
    }

   static public int[] sortArrayByParity1(int[] A) {
        int len = A.length;
        Integer[] temp = new Integer[len];
       for (int i = 0; i < len; i++) {
           temp[i] = A[i];
       }
        Arrays.sort(temp,new Comparator<Integer>(){

            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o1.intValue()%2, o2.intValue()%2);
            }
        });

        System.out.println(A);
       for (int i = 0; i < len; i++) {
           A[i] = temp[i];
       }
        return A;
    }

    static public int[] sortArrayByParity2(int[] A) {

        return Arrays.stream(A).boxed().sorted(new Comparator<Integer>(){

            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(o1.intValue()%2, o2.intValue()%2);
            }
        }).mapToInt(new ToIntFunction<Integer>() {
            @Override
            public int applyAsInt(Integer value) {
                return value.intValue();
            }
        }).toArray();
    }
    static public int[] sortArrayByParity(int[] A){
        int i=0, j = A.length-1;
        while (i<j){
            if (A[i]%2>A[j]%2){
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
            if (A[i]%2==0)i++;
            if (A[j]%2==1)j--;
        }

        return A;
    }
}
