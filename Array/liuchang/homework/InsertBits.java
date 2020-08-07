public class InsertBits {

    public static int insertBits(int N, int M, int i, int j) {
        if (N==0){
            return M;
        }
        String str1 = String.valueOf(N);
        String str2 = String.valueOf(M);
        StringBuilder stringBuilder = new StringBuilder();
        if (str2.length() < j) {
            stringBuilder.append(str2);
            for (int k = 0; k < j+1 - str2.length(); k++) {
                stringBuilder.append("0");
            }
        }
        StringBuilder stringBuilder1 = new StringBuilder();
        stringBuilder1.append(str1);
        stringBuilder.reverse();
        stringBuilder1.reverse();
        char[] chars = stringBuilder1.toString().toCharArray();
        char[] chars1 = stringBuilder.toString().toCharArray();
        for (int k = 0; k <stringBuilder.toString().length() ; k++) {
            chars[k] =chars1[k];
        }
        StringBuilder stringBuilder2 = new StringBuilder();
        stringBuilder2.append(String.valueOf(chars));
        stringBuilder2.reverse();
        return Integer.parseInt(stringBuilder2.toString());
    }

    public static void main(String[] args) {
        System.out.println(insertBits(1000000000,10011,2,6));
    }

}
