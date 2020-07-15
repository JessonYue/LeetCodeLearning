package day45_0715;

public class day45_leetcode283 {

    public static void main(String[] args) {
        int[] arr = {0,1,0,3,12};
        moveZeroes(arr);
    }

    public static void moveZeroes(int[] nums) {
        if(nums.length<=1)
            return;
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
                if(nums[i] != 0 ){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j++] = temp;
                }

        }
        for (int i = 0; i < nums.length; i++) {
            System.out.println(nums[i]);
        }
    }
}
