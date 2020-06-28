//
// Created by 谢涛 on 2020/4/17.
//

#include <stdio.h>


 int main(){
#define MAX(a, b) ((a)>(b) ? (a) : (b))
     int arrayNesting(int* nums, int numsSize){
         int res = 0;
         for(int i= 0; i < numsSize; i++){
             int start = nums[i];
             int count = 0;
             do{
                 start = nums[start];
                 count++;
             }while(start != nums[i]);
             res = MAX(count,res);
         }
         return res;
     }
     return 0;
}
