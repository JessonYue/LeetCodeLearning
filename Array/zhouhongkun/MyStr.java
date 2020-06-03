package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        String haystack = "hello";
        String needle = "lo";

        System.out.println(String.format("%s在%s中第一次出现的位置为%d", needle, haystack, strStrOther(haystack, needle)));
    }

    //方法一 使用String对象的indexOf方法返回索引
    private static int strStr(String haystack, String needle){
        if(needle.isEmpty()){
            return 0;
        }

        if(haystack == null){
            return -1;
        }

        int lenh = haystack.length();
        int lenn = needle.length();

        if(lenn > lenh){
            return -1;
        }

        return haystack.indexOf(needle);
    }

    //方法二 通过遍历，使用String对象的substring方法判断是否包含needle，包含则返回i
    private static int strStrOther(String haystack, String needle){
        if(needle.isEmpty()){
            return 0;
        }

        if(haystack == null){
            return -1;
        }

        int lenh = haystack.length();
        int lenn = needle.length();

        if(lenn > lenh){
            return -1;
        }

        for(int i=0; i<lenh-lenn+1; i++){
            if(haystack.substring(i, i+lenn) != null && haystack.substring(i, i+lenn).equals(needle)){
                return i;
            }
        }
        return -1;
    }
}
