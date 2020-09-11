#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
#include <deque>
#include <vector>
#include <unordered_set>

using namespace std;
const char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

string toHex(int num) {
    if (num == 0) {
        return "0";
    }

    string str = "";
    int tmp;
    int count = 0;
    while (num != 0 && count < 8) {
        tmp = num & 0xF;
        str.insert(0, 1, map[tmp]);
//        str = map[tmp] + str;
        num = num >> 4;
        count++;
    }

    return str;
}

/**
 * 面试题 05.01. 插入
 * 插入。给定两个32位的整数N与M，以及表示比特位置的i与j。
 * 编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束。
 * 假定从j位到i位足以容纳M，也即若M = 10 011，那么j和i之间至少可容纳5个位。
 * 例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M
 */
int insertBits(int N, int M, int i, int j) {
    for (int k = i; k <= j; k++) {
        N = N & ~(1 << k);
    }

    M = M << i;
    return N | M;
}

string int2bit(int n) {
    string s;
    int a;
    while (n > 0) {
        a = n % 2;
        n = n / 2;
        s += map[a];
    }
    return s;
}

bool hasAlternatingBits(int n) {
    string s = int2bit(n);
    for (int i = 0, j = i + 1, count = s.size(); i < count; i++, j++) {
        if (j < count && s[i] == s[j]) {
            return false;
        }
    }
    return true;
}

/**
 * 217. 存在重复元素
 * 给定一个整数数组，判断是否存在重复元素。
 * 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 * @param nums
 * @return
 */
bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    vector<int>::iterator begin = nums.begin();
    while (begin != nums.end()) {
        auto pair = set.insert(*begin);
        if (!pair.second) {
            return true;
        }
        begin++;
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << toHex(26) << std::endl;
    std::cout << hasAlternatingBits(5) << std::endl;
    vector<int> v;
    v.push_back(0);
    cout << containsDuplicate(v) << endl;
    return 0;
}

