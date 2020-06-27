


int findNumbers(int* nums, int numsSize){

   int i;
   int count;
   for(i = 0;i<numsSize;i++){
      int num = nums[i];
      if(num == 0){
          continue;
      }
      int deg = 0;
      //循环，不断除以10
      while(num != 0){
          deg ++;
          num =  num/10;
      }
      if(deg%2 == 0){//偶数数
         count ++;
      }
   }

   return count;
}