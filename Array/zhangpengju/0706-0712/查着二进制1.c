

//参考结论 要消除整数n最低位的1，可以使用 n = n & (n-1)。
int countBits(int n) {
    int count = 0;
    while(n != 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}