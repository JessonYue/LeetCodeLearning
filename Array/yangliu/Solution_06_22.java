import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.CountDownLatch;

public class Solution_06_22 {

    public int arrayNesting(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int j = i, count = 0;
            while(nums[j]!=-1){
                count++;
                int tmp = nums[j];
                nums[j] = -1;//标记被索引过的为-1
                j = tmp;
            }
            result = Math.max(result, count);
        }
        return result;
    }


}
