import java.util.Scanner;

public class Homework_002 {

    // 爬楼梯，LeetCode第70题
    public void homework_002_070() {
        int target = 1, stepNumber;
        System.out.print("输入目标阶梯数字：");
        Scanner scanner = new Scanner(System.in);
        target = scanner.nextInt();
        stepNumber = climbStairs(target);
        System.out.println(String.format("共有 %d 种爬楼梯方法", stepNumber));
    }

    private int climbStairs(int target) {
        return climbStairs(0, target);
    }
    // 0, 3 --- 1, 3(2, 3(3, 3, 4, 3), 3, 3) + 2, 3(3, 3, 4, 3)
    private int climbStairs(int i, int target) {
        if (i > target)
            return 0;
        if (i == target)
            return 1;
        return climbStairs(i + 1, target) + climbStairs(i + 2, target);
    }
}
