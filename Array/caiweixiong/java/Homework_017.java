public class Homework_017 {

    // 统计位数为偶数的数字，LeetCode第1295题
    void homework_017_1295() {
        int[] nums = {12, 345, 2, 6, 7896};
        System.out.println(String.format("the double bit num have : %d", findNumbers(nums)));
    }

    private int findNumbers(int[] nums) {
        if (nums == null || nums.length <= 0) {
            return 0;
        }
        int count = 0, bit = 0, value = 0;
        for (int i = 0; i < nums.length; i++) {
            bit = 0;
            value = nums[i];
            do {
                value /= 10;
                bit++;
            } while (value != 0);
            if ((bit % 2) == 0)
                count++;
        }
        return count;
    }
}
