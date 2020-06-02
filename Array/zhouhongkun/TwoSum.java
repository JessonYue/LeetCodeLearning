public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] nums = {1, 3, 5, 7, 9, 11};
        int target = 16;
        int temp[] = twoSum(nums, target);
        System.out.println(String.format("i=%d, j=%d", temp[0], temp[1]));

    }
    public static int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}