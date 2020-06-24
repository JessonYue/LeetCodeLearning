public class Homework_016 {

    // 数组嵌套，LeetCode第565题
    void homework_016_565() {
        int[] A = {5, 4, 0, 3, 1, 6, 2};
        int max = arrayNesting(A);
        System.out.println(String.format("max = %d", max));
    }

    private int arrayNesting(int[] nums) {
        if (nums == null || nums.length <= 0)
            return 0;
        boolean[] visit = new boolean[nums.length]; // 记录当前位置是否已经访问过
        int max = 1, index = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!visit[i]) {
                count = 0;
                index = nums[i];
                do {
                    index = nums[index];
                    count++;
                    visit[index] = true;
                } while (index != nums[i]);
                max = max > count ? max : count;
            }
        }
        return max;
    }
}
