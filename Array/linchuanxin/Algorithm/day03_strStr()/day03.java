package day03;

public class day03 {

    public static void main(String[] args) {
        String a = "sdfwsdfsfbodysdfsdf";
        String b = "body";
        System.out.println(strStr2(a,b));
    }

    /*字符截取比较,目标b与a截取比较*/
    private static int strStr1(String a,String b) {
        int aLength = a.length();
        int bLength = b.length();
        if(aLength< bLength){
            return -1;
        }else if(a.equals("") && b.equals("")){
            return 0;
        }else if(a.equals("")){
            return -1;
        }else if (b.equals("")){
            return 0;
        }
        for (int i = 0; i < aLength - bLength; i++) {
            String check = a.substring(i, i + bLength);
            if(check.equals(b)){
                return i;
            }
        }
        return -1;
    }

    /*
    * 目标b第一个与a第一个比较
    * 没有a就移到下一个，知道有与b第一个字符相同，从a截取b长度，进行比较
    *
    * */
    private static int strStr2(String a,String b) {
        int aLength = a.length();
        int bLength = b.length();
        if(aLength< bLength){
            return -1;
        }else if(a.equals("") && b.equals("")){
            return 0;
        }else if(a.equals("")){
            return -1;
        }else if (b.equals("")){
            return 0;
        }
        char bCheck = b.charAt(0);
        for (int i = 0; i < aLength - bLength; i++) {
            char aCheck = a.charAt(i);
            if(aCheck == bCheck){
                String check = a.substring(i, i + bLength);
                if(check.equals(b)){
                    return i;
                }
            }
        }
        return -1;
    }
}
