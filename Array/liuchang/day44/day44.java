public class day44 {

    public static int firstUniqChar(String str) {
        int length = str.length();
//        printf("%d\n", length);
        int n = 0;
        char chars[] = str.toCharArray();
        while (chars[n]!='\0' ) {
            int index = n;
            for (int i = 0; i < length; ++i) {
                if (chars[index] == chars[i] && i != index) {
                    break;
                } else if (i == (length - 1)) {
                    return n;
                }
            }
            index++;
            n++;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("====="+firstUniqChar("loveleetcode"));
    }
}
