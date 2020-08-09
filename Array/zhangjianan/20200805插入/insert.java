class Solution {
    public int insertBits(int N, int M, int i, int j) {
        for(int k=i;k<=j;k++){
           int a= N & (1<<k);
            if(a!=0){
                N-=(1<<k);
            }
        }
        N+=(M<<i);
        return N;
    }
}