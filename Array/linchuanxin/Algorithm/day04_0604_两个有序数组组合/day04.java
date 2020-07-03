package day04;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class day04 {

    public static void main(String[] args) {
        int[] num1 = {1,2,3,7,0,0};
        int[] num2 = {2,4,5};
        sortArr1(num1,3,num2,3);
        for (int i = 0; i < num1.length; i++) {
            System.out.println(num1[i]);
        }
    }


    /*api调用*/
    public static void sortArr(int[] num1,int m,int[] num2,int n){
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            list.add(num1[i]);
        }

        for (int i = 0; i < n; i++) {
            list.add(num2[i]);
        }

        list.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        });

        for (int i = 0; i < m + n; i++) {
            num1[i] = list.get(i);
        }

    }

    /*三指针合作*/
    public static void sortArr1(int[] num1,int m,int[] num2,int n){
        int a = 0;
        int b = 0;
        int current = 0;
        int[] extra = num1.clone();


        while (a < m && b < n){
            if(extra[a] < num2[b]){
                num1[current] = extra[a];
                a++;
            }else{
                num1[current] = num2[b];
                b++;
            }
            current++;
        }
        if(a == m){
            //说明num2可以继续
            for (int i = current; i < m + n; i++) {
                num1[i] = num2[b++];
            }
        }else if(b == n){
            //说明num1可以继续
            for (int i = current; i < m + n; i++) {
                num1[i] = extra[a++];
            }
        }
    }
}
