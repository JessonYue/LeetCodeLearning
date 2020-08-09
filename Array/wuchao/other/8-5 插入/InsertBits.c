//
// Created by 吴超 on 2020/8/5.
//
int insertBits(int N, int M, int i, int j){
    unsigned int mask = (1<<(j-i+1))-1;
    int m = ~(mask<<i);
    return (N&m)|(M<<i);
}

