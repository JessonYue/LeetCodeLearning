public class Solution_1047 {
    public String removeDuplicates(String S) {
        StringBuilder builder = new StringBuilder();
        int strLength = 0;
        for (char str: S.toCharArray()) {
            if (strLength != 0 && str == builder.charAt(strLength - 1)) {
                builder.deleteCharAt(strLength-- -1);
            }else {
                builder.append(str);
                strLength++;
            }
        }
        return builder.toString();
    }
}
