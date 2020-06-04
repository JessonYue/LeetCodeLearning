import java.util.Scanner;

public class Homework_001 {

    // 两数之和II，注意，它们是有序表，LeetCode第1题
    public void homework_001_001() {
        int target, result[], array[] = {3, 8, 9, 21, 30};
        System.out.print("输入目标数字：");
        Scanner scanner = new Scanner(System.in);
        target = scanner.nextInt();
        result = twoSum(array, array.length, target);
        if (result == null) {
            System.out.println("没有发现合适的索引");
        } else {
            System.out.println(String.format("目标的索引为：[%d, %d]", result[0], result[1]));
        }
    }

    private int[] twoSum(int[] array, int length, int target) {
        // 通过一头一尾的索引，减少循环的次数
        int i = 0, j = length - 1;
        while (i < j) {
            if (array[i] + array[j] == target) {
                return new int[]{++i, ++j};
            } else {
                // 当后面的元素大于等于目标数或者两数之和大于目标数
                if ((array[j] >= target) || (array[i] + array[j] > target)) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return null;
    }
}
