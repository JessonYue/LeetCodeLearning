package L6;



public class Solution {
    /**
     * 
     * @param s
     * @param numRows
     * @return
     */
    public static String convert(String s, int numRows) {
        char[] charArray = s.toCharArray();
        int length = charArray.length;
        if (length <= numRows || numRows == 1) {
            return s;
        }
        String[] boxes = new String[numRows];
        int boxesIndex = 0;
        boolean change = false;
        for (char c : charArray) {
            if (boxesIndex == 0 || boxesIndex == numRows - 1) {
                change = !change;
            }
            if (boxes[boxesIndex] == null) {
                boxes[boxesIndex] = "";
            }
            boxes[change ? boxesIndex++ : boxesIndex--] += c;

        }
        StringBuilder sb = new StringBuilder();
        for (String box : boxes) {
            sb.append(box);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String leetcodeishiring = convert("AB", 1);
        System.out.println(leetcodeishiring);
    }
}
