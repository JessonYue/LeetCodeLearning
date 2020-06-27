package day23;

public class day23_leetcode1295 {

    public static int findNumbers(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if(String.valueOf(nums[i]).length()%2 == 0){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int i = 0;
        for(;i<10;){
            System.out.println(String.valueOf(i));
        }
//        for (;;){
//            System.out.println("for print");
//        }
    }
}
