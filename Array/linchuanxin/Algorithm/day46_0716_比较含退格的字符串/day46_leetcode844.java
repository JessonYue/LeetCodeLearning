package day46_0716;

import com.sun.corba.se.impl.resolver.SplitLocalResolverImpl;

public class day46_leetcode844 {

    public static void main(String[] args) {
        boolean b = backspaceCompare1("ab##", "c#d#");
        if (b)
            System.out.println("dui");
    }

    //a##c
    public static boolean backspaceCompare(String S, String T) {
        String temp = "";
        for(int i = 0; i < S.length();i++){
            char c = S.charAt(i);
            if(c == '#'){
                if(temp.length()>0){
                    temp = temp.substring(0,temp.length()-1);
                }else{
                    temp = "";
                }
                continue;
            }
            temp = temp+c;
        }
        System.out.println(temp);

        String temp1 = "";
        for(int i = 0; i < T.length();i++){
            char c = T.charAt(i);
            if(c == '#'){
                if(temp1.length()>0){
                    temp1 = temp1.substring(0,temp1.length()-1);
                }else{
                    temp1 = "";
                }
                continue;
            }
            temp1 = temp1+c;
        }
        System.out.println(temp1);


        if(temp.equals(temp1))
            return true;
        return false;
    }

    public static String returnDeleteCount(String str){
        if(str==null || str.length()==0)
            return null;
        int index = 0;
        String temp = "";
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if(chars[i]!='#'){
                chars[index++] = chars[i];
            }else{
                if(index>0)
                    index--;
            }
        }

        for (int i = 0; i < index; i++) {
            temp = temp+chars[i];
        }
        return temp;
    }


    public static boolean backspaceCompare1(String S, String T) {

        String s = returnDeleteCount(S);
        String t = returnDeleteCount(T);
        if(s.length() != t.length())
            return false;
        char[] chars1 = s.toCharArray();
        char[] chars2 = t.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            if(chars1[i]!=chars2[i])
                return false;
        }
        return true;

    }
}
