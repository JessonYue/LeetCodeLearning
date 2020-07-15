package day44_0714;



public class day44_leetcode405 {

    public static String toHex(int num) {
//        char[] chars = "0123456789abcdef".toCharArray();
//        StringBuilder sb = new StringBuilder();
//        while (num!=0){
//            sb = sb.append(chars[num%16]);
//            num = num/16;
//        }
//        return sb.toString();
        StringBuffer buffer = new StringBuffer();
        char[] arr ="0123456789abcdef".toCharArray();
        if(num==0) return "0";
        while (num!=0){
            int tmp=num&15;
            buffer.append(arr[tmp]);
            num=num>>>4;
        }

        return buffer.reverse().toString();
    }
    public static void main(String[] args) {
        System.out.println(toHex(26));

        //Integer.toHexString(26);
        System.out.println(26&15);
        System.out.println(10>>>4);
    }

}
