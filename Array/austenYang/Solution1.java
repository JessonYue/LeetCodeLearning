
public class Solution1 {
    /**
     * 思路1.
     * 双层循序 
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] result = twoSum(new int[] { 1, 3, 4, 5 }, 9);
        StringBuffer sb = new StringBuffer();
        sb.append("数组：「");
        for (int i = 0; i < result.length; i++) {
            sb.append(result[i]);
            if (i != result.length -1 ) {
                sb.append("-");
            }
        }
        sb.append("」");

        System.out.println(sb.toString());
    }

}