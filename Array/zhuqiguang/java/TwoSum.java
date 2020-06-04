import java.util.HashMap;

/**
 * 2020.06.1
 * 167. 两数之和 II - 输入有序数组
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * <p>
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * <p>
 * 说明:
 * <p>
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 示例:
 * <p>
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */
public class TwoSum {
    public static void main(String[] args) {
//        int[] numbers = {2, 7, 11, 15};
//        int target = 9;//
        int[] numbers = {2, 3, 9, 10};
        int target = 19;
        int[] ints = hashFind(numbers, target);
        for (int i = 0; i < ints.length; i++) {
            System.out.println(ints[i]);
        }
    }

    /**
     * 暴力解法，时间复杂度为O（n^2）
     *
     * @param nums
     * @param target
     * @return
     */
    private static int[] simpleFind(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            int first = nums[i];
            int second = target - first;
            for (int j = i + 1; j < nums.length; j++) {
                if (second == nums[j]) {
                    return new int[]{i, j};
                }
            }
        }
        throw new RuntimeException();
    }

    /**
     * 一遍hashmap:时间复杂度为O（n）
     */
    private static int[] hashFind(int[] nums, int target) {
        HashMap<Integer, Integer> firstMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (firstMap.containsKey(target - nums[i])) {
                Integer second = firstMap.get(target - nums[i]);
                return new int[]{second, i};
            }
            firstMap.put(nums[i], i);
        }
        throw new RuntimeException();
    }
}
