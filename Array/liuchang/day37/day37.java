public class day37 {


    public static String changeString(String str){
        char[] chars = str.toCharArray();
        int count = chars.length;
        char newString[] = new char[count];
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < count ; ++j) {
                if (newString[j]=='\0'){
                    newString[j] = chars[i];
                    break;
                }
            }
        }
        return String.valueOf(newString);

    }


    public static void main(String[] args) {
        System.out.println(changeString("abcdef"));
    }

}
