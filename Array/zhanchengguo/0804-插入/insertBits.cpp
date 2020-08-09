#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

using namespace std;

int insertBits(int N, int M, int i, int j) {
    for (int k = i; k <= j; k++) {
        if (N & (1 << k)) {
            N -= (1 << k);
        }
    }
    N += (M << i);
    return N;
}

int main() {
    int result = insertBits(10000000000, 10011, 2, 6);
    cout << bitset<sizeof(int) * 8>(result) << endl;
    return 0;
}