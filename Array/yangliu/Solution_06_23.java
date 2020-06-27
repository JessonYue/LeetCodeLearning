public class Solution_06_23 {

    public int findNumbers(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int count = 1;
            while (num / 10 > 0) {
                num = num / 10;
                count++;
            }
            if (count % 2 == 0)
                result++;

        }

        return result;
    }



}
