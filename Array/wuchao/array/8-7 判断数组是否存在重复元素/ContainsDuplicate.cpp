//
// Created by 吴超 on 2020/8/7.
//
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int item:nums){
            if(m[item]>0) return true;
            m[item]++;
        }
        return false;
    }
};
