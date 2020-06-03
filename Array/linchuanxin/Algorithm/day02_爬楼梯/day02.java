package day02;

public class day02 {

    public static void main(String[] args) {
        for (int i = 1; i < 10; i++) {
            //System.out.println(i+"-----"+climb1(i));
            System.out.println(i+"-----"+climb2(i));
        }
    }


    /*递归
    * 根据斐波拉契数列
    * */
    public static int climb1(int n){
        if(n == 1 || n==2){
            return n;
        }else{
            return climb1(n-1)+climb1(n-2);
        }
    }

    /*
    遍历法
    * */
    public static int climb2(int n){
        if(n == 1 || n==2){
            return n;
        }
        int temp = 0;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            temp = first + second;
            first = second;
            second = temp;
        }
        return temp;
    }
	
	//6.3增加动态规划解法
	/*
    *
    * 动态规划
    *
    * 最优子结构   n-1  n-2
    * 边界   f1=1   f2=2
    * 状态转移方程   n-1   +   n-2
    * */
    private static int climb3(int n){
        if(n==1 || n==2){
            return n;
        }
        int[] arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i-1]+arr[i-2];
        }
        return arr[n];

    }
}

