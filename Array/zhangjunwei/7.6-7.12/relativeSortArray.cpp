//
// Created by 张俊伟 on 2020/7/12.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int tmp = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            for (int j = 0; j < arr1.size(); ++j) {
                if(arr1[j]==arr2[i]){
                    swap(arr1[tmp],arr1[j]);
                    tmp++;
                }
            }
        }
        sort(arr1.begin()+tmp,arr1.end());
        return arr1;
    }
};