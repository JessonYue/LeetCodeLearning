public class day45 {
    public String toHex(int num) {
        char[] hex = "0123456789abcdef".toCharArray();
        StringBuilder str=new StringBuilder();
        while(num != 0){
            int end = num&15;//比较二进制的差异
            //// System.out.println(end);
            str.append(hex[end]);
            //无符号右移4位
            num >>>=4;
        }
        if(str.length() == 0){
            str.append("0");
        }
        //反转字符
        StringBuilder str0=str.reverse();

        return str0.toString();
    }

}
