#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

string toHex(int num) {
    if (num == 0) {
        return "0";
    }
    string res;
    string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    unsigned int nums = num;
    while (nums) {
        res = hex[nums % 16] + res;
        nums = nums / 16;
    }
    return res;
}


int main() {
    string result1 = toHex(26);
    printf("result1 is %s\n", result1.c_str());
    string result2 = toHex(-1);
    printf("result2 is %s\n", result2.c_str());
    return 0;
}