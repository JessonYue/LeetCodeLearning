#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool hasAlternatingBits(int n) {
    string res;
    string hex[] = {"0", "1"};
    while (n) {
        res = hex[n % 2] + res;
        n = n / 2;
    }
    char lastC = res[0];
    for(int i = 1;i< res.size();i++){
        if(lastC == res[i]){
            return false;
        }
        lastC = res[i];
    }
    return true;
}


int main() {
    bool result = hasAlternatingBits(5);
    printf("result is %d",result);
    return 0;
}