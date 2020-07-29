//
// Created by 吴超 on 2020/7/29.
//
#include <stdio.h>
/**
 * 卷积
 */

 long long convolution(long* n,long* h,int sizeOfConvolution){
     long long result = 0;
     for(int i=0;i<sizeOfConvolution+1;i++){
         result+=n[i]*h[sizeOfConvolution-i];
     }
     return result;
 }

 int main(){
     long n[] = {1,2,3,4};
     long h[] = {1,2,3,4};
     printf("convolution of %d value is %lld\n",0,convolution(n,h,0));
     printf("convolution of %d value is %lld\n",1,convolution(n,h,1));
     printf("convolution of %d value is %lld\n",2,convolution(n,h,2));
     printf("convolution of %d value is %lld\n",3,convolution(n,h,3));
 }

