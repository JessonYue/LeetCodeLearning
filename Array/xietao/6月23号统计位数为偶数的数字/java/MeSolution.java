import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MeSolution {
    class Solution {
        public int findNumbers(int[] nums) {
            int count = 0;
            for(int i = 0; i < nums.length;i++){
                if(String.valueOf(nums[i]).length()%2 == 0){
                    count++;
                }
            }
            return count++;
        }
    }
}
