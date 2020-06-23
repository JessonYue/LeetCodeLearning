package L565;

public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            int index = i;
            while (nums[index] != -1) {
                index = nums[index];
                nums[i] = -1;
                count++;
            }
            if (count > res) res = count;
        }
        return res;
    }
}
