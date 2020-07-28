//
// Created by 吴超 on 2020/7/28.
//
#include <stdlib.h>
#include <vector>
#include <unordered_set>

using std::vector;
using std::map;
using std::unordered_set;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2;
        for(int i:nums2){
            if(set1.count(i)){
                set2.insert(i);
            }
        }
        return vector<int>(set2.begin(),set2.end());
    }
};
