217. 存在重复元素

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 

    }
};