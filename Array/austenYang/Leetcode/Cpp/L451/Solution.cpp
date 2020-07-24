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
        for (const auto &c :s) {
            ++ump[c];
        }
        priority_queue<pair<int, char>> pq;
        for (const auto &m : ump) {
            pq.push({m.second, m.first});
        }
        string ret;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string s = solution.frequencySort("tree");
    cout << s << endl;
    return 0;
}