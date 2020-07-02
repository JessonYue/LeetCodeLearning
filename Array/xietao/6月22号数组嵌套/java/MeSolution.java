import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {
    static class Solution {
        public int arrayNesting(int[] nums) {
            int res = 0;
            for(int i = 0; i < nums.length; i++){
                int start = nums[i],count = 0;
                do{
                    start = nums[start];
                    count++;

                }while(start != nums[i]);
                res = Math.max(res, count);
            }
            return res;
        }
    }
}
