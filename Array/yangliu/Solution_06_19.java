import java.util.Stack;

public class Solution_06_19 {

    public String removeDuplicates(String S) {
        char ch[] = new char[20000];
        char[] chars = S.toCharArray();
        int index = 0;//标记当前位置
        for (int i = 0; i < chars.length; i++) {
            if (index == 0) {
                ch[index++] = chars[i];
            } else {
                if (ch[index - 1] == chars[i]) index--;
                else ch[index++] = chars[i];
            }

        }
        String s="";
        for (int i=0;i<index;i++){
            s+=ch[i];
        }
        return s;

    }


}
