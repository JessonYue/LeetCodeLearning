package day65_0804_leetcode405;



public class day65_leetcode405 {

    public static String toHex(int num) {
        StringBuilder res = new StringBuilder();
        char[] arr = "0123456789abcdef".toCharArray();
        if(num == 0)
            return "0";
        while (num != 0){
            int tmp = num & 15;
            res.append(arr[tmp]);
            num = num >>> 4;
        }
        return res.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println(day65_leetcode405.toHex(26));
    }


}
