public class SolutionJava {
    public int arrayNesting(int[] nums) {
        int ret = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            int next = i;
            while (nums[next] != -1) {
                int temp = next;
                next = nums[next];
                nums[temp] = -1;
                count++;
            }
            ret = Math.max(ret, count);
        }
        return ret;
    }

}
