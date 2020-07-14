#include <iostream>
#include "stack"
#include "string"
#include "vector"
#include "map"

using namespace std;

int firstUniqChar(string s);

int main() {
    int i = firstUniqChar("cc");
    printf("result is %d", i);
    return 0;
}

/**
 * 思路：遍历记录每个字符出现的次数，在遍历字符出现次数为1的下标
 * @param s
 * @return
 */
int firstUniqChar(string s) {
    map<int, int> map;
    for (char c:s) {
        map[c] += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (map[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

