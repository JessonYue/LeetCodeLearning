//
// Created by austenYang on 2020/7/22.
//
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }

        vector<string> vec(s.size() + 1);
        string res;
        for (const auto &m : ump) {
            vec[m.second].append(m.second, m.first);
        }
        for (int i = s.size(); i > 0; --i) {
            if (!vec[i].empty()) {
                res.append(vec[i]);
            }
        }
        return res;
    }
};

int main() {

//    int x ;
//    auto y = 0.0f;
//    cout << sizeof(y) << endl;
    Solution solution;
    string s = solution.frequencySort("tree");
    cout << s << endl;

    return 0;
}