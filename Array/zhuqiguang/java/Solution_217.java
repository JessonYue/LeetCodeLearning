import java.util.HashMap;
import java.util.Set;

public class Solution_217 {
    public boolean containsDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) return false;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i=0;i<nums.length;i++) {
            if (!hashMap.containsKey(nums[i])) {
                hashMap.put(nums[i], i);
            }else {
                return true;
            }
        }
        return false;
    }
}
