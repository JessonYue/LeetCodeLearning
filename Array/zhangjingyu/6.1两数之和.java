public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        int[] arr = {2, 7, 11, 15};
        Sysou(twoSum(arr,9));
    }

    public int[] twoSum(int[] nums, int target) {
        int i=0;
        int j=nums.length-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum < target){
                i++;
            } else if((sum > target)){
                j--;
            } else{
                return new int[]{i+1, j+1};
            }
        }
        return new int[]{-1, -1};
    }

    /**
     * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
     *
     * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
     *
     * 说明:
     *
     * 返回的下标值（index1 和 index2）不是从零开始的。
     * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
     * 示例:
     *
     * 输入: numbers = [2, 7, 11, 15], target = 9
     * 输出: [1,2]
     * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2
     * @param arr
     * @param num
     */
    private String  getSum(int[] arr, int num) {
        if(num>arr[arr.length-1]) {
            return null;
        }
        for(int i = 0; i < arr.length; i++) {
            for(int j = i+1; j < arr.length; j++) {
                if(arr[i]+arr[j]==num) {
                    return "["+(i+1)+","+(j+1)+"]";
                }
            }
        }
        return null;
    }


    /**
     * 打印数组
     * @param arr
     */
    public void Sysou(int[] arr){
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

    /**
     * 二分查找
     * @param list
     * @param item
     */
    public void BinarySearch(int[] list, int item){
        int low = 0;
        int high = list.length - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int guess = list[mid];
            if(guess == item) {
                System.out.println(guess + "的位置为" + mid);
            }
            if(guess > item) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
    }




}