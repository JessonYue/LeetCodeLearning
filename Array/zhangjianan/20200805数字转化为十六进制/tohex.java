class Solution {
    public String toHex(int num) {
        StringBuffer    sb=new StringBuffer();
        String s="0123456789abcdef";
        while(num!=0){
            int index=num&15;
            sb.append(s.charAt(index));
            num>>>=4;
        }
        if(sb.length()==0)sb.append(0);
        return sb.reverse().toString();
    }
}