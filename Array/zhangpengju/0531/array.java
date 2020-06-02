public class array {
    //给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    //不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
    /**
     * 思路分析：
     *    前提条件是有序的，例如 1 1 2 2 4 4 4 5 6 6
     *    可参考冒泡排序思维，选出来参照元素，然后交换，挪动数组下表指针
     *    1，定义比较位索引，发现不同的，则后移 然后将不同的赋值给当前移动到的位置
     *    2，循环遍历，取出所有元素参与计较计算
     * @param nums
     * @return
     */
    public int removeDuplicates(int[] nums) {
        if(nums == null){
            return 0;
        }
        int length = nums.length;
        if(length <=1){
            return length;
        }
        
        //来一轮互换  前提是有序的
        int index = 0;
        for(int i= 1;i<length;i++){
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
            }
        }  
        return index+1;  
    }
}