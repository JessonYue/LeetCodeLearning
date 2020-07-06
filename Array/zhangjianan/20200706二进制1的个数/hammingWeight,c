int hammingWeight(uint32_t n) {
    int sum=0;
    while(n!=0){
        sum+=n&1;
        n=n>>1;
    }
    return sum;
}
int hammingWeight1(uint32_t n) {
    int sum=0;
    while(n!=0){
        n&=n-1;
        sum++;
    }
    return sum;
}