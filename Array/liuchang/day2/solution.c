#include <stdio.h>

int climbStairs(int i);

int main() {
    printf("%i\n",climbStairs(5));
    return climbStairs(5);
}

int climbStairs(int i) {
    int count[i+1];
    count[0] = 1;
    count[1] = 1;
    for (int j = 2; j <= i ; j++) {
        count[j] = count[j-1]+count[j-2];
    }
    return count[i];
}