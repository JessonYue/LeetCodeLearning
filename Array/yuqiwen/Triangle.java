package leetCode;


import java.util.ArrayList;
import java.util.List;

/**
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 杨辉三角
 */
public class Triangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) {
            return result;
        }
        for (int i = 1; i <= numRows; i++) {
            List<Integer> sub = new ArrayList<>();
            for (int j = 1; j <= i; j++) {
                if (j == 1 || j == i) {
                    sub.add(1);
                    System.out.print(" 1 ");
                } else {
                    sub.add(result.get(i - 2).get(j-1) + result.get(i - 2).get(j - 2));
                    System.out.print(" " + (result.get(i - 2).get(j-1) + result.get(i - 2).get(j - 2)) + " ");
                }

            }
            result.add(sub);
            System.out.println();
        }

        return result;
    }

    public static void main(String[] args) {
        new Triangle().generate(5);
    }

}
