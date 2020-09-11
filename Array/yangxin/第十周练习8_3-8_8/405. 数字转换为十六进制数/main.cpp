#include <iostream>
#include <string>

std::string toHex(int num) {
    if (num == 0) {
        return "0";
    }
    const char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    std::string str = "";
    int tmp;
    int count = 0;
    while (num != 0 && count < 8) {
        tmp = num & 0xF;
        str = map[tmp] + str;
        num = num >> 4;
        count++;
    }
    return str;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << toHex(26) << std::endl;
    return 0;
}
