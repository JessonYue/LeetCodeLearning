1.给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
思路:
利用快慢指针, 数组完成排序后，我们可以放置两个指针 i 和 j，其中 ii 是慢指针，而 j 是快指针。只要 nums[i] = nums[j]，我们就增加 j以跳过重复项。
java:
public int removeDuplicates(int[] nums) {
      int i = 0;
      for(int j = 0; j < nums.length; j++){
          if(nums[i] != nums[j]){
              i++;
              nums[i] = nums[j];
          }
      }
      return nums.length == 0 ? 0 : i+1;
  }
c:
int removeDuplicates(int* nums, int numsSize){
  int i = 0;
  for(int j = 0; j < numsSize; j++){
      if(nums[i] != nums[j]){
             i++;
             nums[i] = nums[j];
         }
  }
  return numsSize == 0 ? 0 : i+1;
}
2.示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9所以返回 [0, 1]
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
思路:
遍历所有元素,判断x元素与target-x相等目标元素
嵌套循环:
java:
public  int[] twoSum(int[] nums, int target) {
  for (int i = 0; i < nums.length; i++) {
      for (int j = i+1; j < nums.length; j++) {
          if(nums[j] == target - nums[i]){
              return new int[] {i,j};    
      }
   }
 }
  throw new Exception("NO NUMBER");
}
时间复杂度: n^2
c:
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int* res = (int *)malloc(sizeof(int) * 2);
  * returnSize=0;
  for(int i = 0; i < numsSize; i++) {
      for(int j = i + 1; j < numsSize; j++) {
          if(nums[j]== target- nums [i]) {
              res[0] = i;
              res[1] = j;
              *returnSize = 2;
              return res;
          }
      }
  }
  return res;
}