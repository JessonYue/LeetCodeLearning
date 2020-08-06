//
// Created by 吴超 on 2020/8/6.
//

#include <stdbool.h>

bool hasAlternatingBits(int n){
    bool flag = (n&1)>0;
    n = n>>1;
    while(n!=0){
        int temp = n&1;
        if((temp>0&&flag)||(temp==0&&!flag)) return false;
        flag = temp > 0;
        n = n >>1;
    }
    return true;
}
