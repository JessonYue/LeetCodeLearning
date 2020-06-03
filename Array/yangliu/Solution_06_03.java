import com.sun.tools.javac.util.StringUtils;

public class Solution_06_03 {
    public static void main(String[] args) {
        int index = getIndex("", "helllo");
        System.out.print(index + "");
    }

    public static int getIndex(String source, String target) {
        int sourceLength = source.length();
        int targetLength = target.length();
        if (targetLength == 0) return 0;
        if (sourceLength == targetLength) return source.equals(target) ? 0 : -1;
        if (sourceLength < targetLength) return -1;
        for (int i = 0; i <= sourceLength - targetLength; i++) {
            if (source.substring(i,i+targetLength).equals(target))return i;
        }
        return -1;
    }
}
