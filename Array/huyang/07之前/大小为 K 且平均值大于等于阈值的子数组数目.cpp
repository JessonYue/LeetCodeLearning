//
// Created by 胡扬 on 2020/6/28.
//

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int p = 0;
    int q = p + k;
    int ret = 0 ;
    int sum = 0;
    for(int i = 0 ; i < k; i++){
        sum+= arr[i];
    }
    if(sum >= threshold*k){
        ret += 1;
    }
    while(q<arr.size()){
        sum =  sum - arr[p] + arr[q];
        if(sum >= threshold*k){
            printf("%d \n", arr[q]);
            ret += 1;
        }
        q++;
        p++;
    }
    return ret;
}


int main(void)
{
    int n[] = {11,13,17,23,29,31,7,5,2,3} ;
    vector<int>  a(n, n+10) ;
    int ret = numOfSubarrays(a,3,5);
    printf("%d \n", ret);

}

