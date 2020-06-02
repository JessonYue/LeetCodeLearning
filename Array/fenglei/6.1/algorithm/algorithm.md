```java
2020.06.1
167. 两数之和 II - 输入有序数组
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
```



Java

```java
	// 自己写
	public void twoNumberSum(int[] numbers, int target) {
		int index1 = 0;
		int index2 = 0;
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 1; i <= numbers.length; i++) {
			int value = target - numbers[i - 1];
			if (map.containsKey(value)) {
				index1 = map.get(value);
				index2 = i;
				System.out.println("index1: " + index1);
				System.out.println("index2: " + index2);
				return;
			} else {
				 map.put(numbers[i - 1], i);
			}
		}
	}

 

// leetCode
leetCode 没找到相同题目
接近题目:
		给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum

public int[] twoSum(int[] nums, int target) {
		int[] indexs = new int[2];
		// 建立k-v ，一一对应的哈希表
		HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			if (hash.containsKey(nums[i])) {
				indexs[0] = i;
				indexs[1] = hash.get(nums[i]);
				return indexs;
			}
			// 将数据存入 key为补数 ，value为下标
			hash.put(target - nums[i], i);
		}
  	// 对这个方法有些疑问 是否造成重复使用？
		// // 双重循环 循环极限为(n^2-n)/2
		// for(int i = 0; i < nums.length; i++){
		// for(int j = nums.length - 1; j > i; j --){
		// if(nums[i]+nums[j] == target){
		// indexs[0] = i;
		// indexs[1] = j;
		// return indexs;
		// }
		// }
		// }
		return indexs;
	}


```



