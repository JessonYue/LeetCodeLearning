给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int> map;
        for(auto c: s) map[c] += 1;
        for(int i=0; i<s.size(); ++i)
            if(map[s[i]] == 1) return i;
        return -1;

    }
};