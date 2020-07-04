package day22;

public class day22_leetcode_arrayNesting565 {



    public static int arrayNesting(int[] nums) {

        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            int start = nums[i];
            do{
                 start = nums[start];
                 count++;
            }while (start != nums[i]);
            res = Math.max(res,count);
        }
        return res;
    }



    public static int arrayNesting2(int[] nums) {

        int res = 0;
        boolean[] visited = new boolean[nums.length];

        for (int i = 0; i < nums.length; i++) {
            if(!visited[i]){
                int start = nums[i],count = 0;
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }while (start != nums[i]);
                res = Math.max(res,count);
            }
        }
        return res;

    }

    public static void main(String[] args) {
        int[] nums = {5,4,0,3,1,6,2};
        System.out.println(arrayNesting2(nums));

    }
}
