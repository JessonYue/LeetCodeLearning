#include <iostream>

using namespace std;

string toHex(int num);

int main(){
    string result = toHex(26);
    printf("result is %s",result.c_str());
    return 0;
}

string toHex(int num) {
    if(num == 0){
        return "0";
    }
    string hex[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
    string res;
    unsigned ns = num;
    while (ns != 0){
        res = hex[ns%16]+res;
        ns /= 16;
    }
    return res;
}