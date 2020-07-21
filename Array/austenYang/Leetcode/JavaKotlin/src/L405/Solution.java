package L405;

public class Solution {

    public static String toHex(int num) {
        char[] chars = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            int end = num & 15;//比较二进制的差异
            //// System.out.println(end);
            sb.append(chars[end]);
            //无符号右移4位
            num >>>= 4;
        }
        if (sb.length() == 0) {
            return "0";
        }
        return sb.reverse().toString();

    }

    public static void main(String[] args) {
        String s = toHex(26);
        System.out.println(s);
    }


}
