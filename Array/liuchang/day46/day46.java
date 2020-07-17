public class day46 {

    public static void moveZeroes(int[] nums) {
        int lastNumber = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                nums[lastNumber] = nums[i];
                if (i != lastNumber) {
                    nums[i] = 0;
                }
                lastNumber++;
            }


        }
        for (int j = 0; j < nums.length; ++j) {
            System.out.println("=====" + nums[j]);
        }
    }

    public static void main(String[] args) {
        moveZeroes(new int[]{1,0,3,0,10});
    }
}
