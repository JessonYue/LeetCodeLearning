#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

void reverseString(vector<char> &s);

int main() {
    char a[] = "hello";
    vector<char> s(a, a + 5);
    reverseString(s);
    for (int i = 0; i < s.size(); ++i) {
        printf("result is %d\n", s.at(i));
    }
    return 0;
}

/**
 * 思路：双向指针，不断移位
 * @param s
 */
void reverseString(vector<char> &s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}