给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        // 用空间换时间 用1001大小的数组记录各数字出现的次数和是否为特殊数字，然后分别输出即可
        vector<int> result;
        short nums[1001][2];
        for(int i = 0; i<1001; i++){
            nums[i][0] = 0;
            nums[i][1] = 0;
        }   
        for(int i = 0; i <arr1.size(); i++)
            nums[arr1[i]][0]++;
        for(int i = 0; i <arr2.size(); i++){
            int index = arr2[i], temp = nums[index][0];
            nums[index][1] = 1;
            while(temp-- > 0)
                result.push_back(index);
        }
        for(int i = 0; i < 1001; i++)
            while(nums[i][0]>0&&nums[i][1]==0){
                result.push_back(i);
                nums[i][0]--;
            }
        return result;

    }
};