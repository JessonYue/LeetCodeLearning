class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set<int> nums1Set(nums1.begin(),nums1.end());
            set<int> resSet;

            for(int i =0; i < nums2.size();++i)
                if(nums1Set.find(nums2[i]) != nums1Set.end())
                    resSet.insert(nums2[i]);

            return  vector<int>(resSet.begin(),resSet.end());
    }
};