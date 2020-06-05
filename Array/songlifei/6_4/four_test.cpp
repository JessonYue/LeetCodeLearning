//
// Created by DF on 2020/6/5.
//

#include "four_test.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    /**
     * 对算法还是一窍不通
     *
     * 还是研究了大佬的算法思路  才写出来 可能算法还是需要刷才能有那种想法吧
     *
     * 感觉思路一直不对方法都是最直接最暴力的一点一点的好几层循环或者判断
     *
     * 不过这次还算是有收获吧 感觉。。。有那么一点点的算法的感觉了不知道是不是错觉
     */

    int A[] = {1, 2, 5, 0, 0, 0};
    int B[] = {2, 3, 6};


    int m = 3 ;
    int n = 3 ;

    int index = m+n-1 ;
    int aindex = m-1 ;
    int bindex = n -1 ;


    while(aindex>=0&&bindex>=0){
        if(A[aindex]<B[bindex]){
            A[index--] = B[bindex--];
        }else{
            A[index--] = A[aindex--];
        }
    }


    for( int i=0;i<6;i++ )

        cout << A[i] <<" " ;

    return 0;
}