package day36_0706;

public class day36_leetcode_offer15 {


    public static void main(String[] args) {
        System.out.println(String.valueOf(hammingWeight(131071)));
    }




    public static int hammingWeight(int n) {
        //0101
        //   1
        //0001
        //0010
        //   1
        //0000
        int res = 0;
        while (n != 0){
            res += n & 1;
            n = n >>> 1;
        }
        return res;

    }
}
