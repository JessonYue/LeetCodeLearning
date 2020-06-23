//索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

//假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。


//思路：环上的任一元素开始遍历都会有相同的结果，在for循环中，使用  while(nums[pos] < len ){
//                nums[pos] += len;
//跳过环上的元素



class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size(), count = 0, temp_count = 0, pos=0;
        for(int i =0 ; i < len; i ++){
            pos = i;
            temp_count = 0;
            while(nums[pos] < len ){
                nums[pos] += len;
                pos = nums[pos] - len;
                temp_count++;
            }
            count = max(count,temp_count);
        }
        return count;
    }
};