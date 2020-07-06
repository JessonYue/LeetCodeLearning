//
//

#include <stdio.h>


int numOfSub(int *arr,int arrSize, int k, int threshold);

int main(){

    int *arr[] = {1,2,3,4,5,6,5,7};
    int count = numOfSub(arr,8,1,2);
    printf("个数是%d",count);
    return 0;
}

//滑动窗口
int numOfSub(int *arr,int arrSize, int k, int threshold){
    //边际检测
    if(k > arrSize){
        return 0;
    }


    //创建窗口索引
    int leftIndex = 0;
    int rightIndex = k-1;

    //求和第一个窗口
    int i,sum = 0;
    for(i = 0;i<k;i++){
        sum += arr[i];
    }

    //目标值
    int targetValue = k * threshold;
    //子集计数器
    int count = 0;
    //判断并开始开始滑动窗口

    if(sum >= targetValue){
        count ++;
    }


    int pre;
    do{
        //开始

        pre = arr[leftIndex];
        //滑动一格
        if((sum - pre + arr[rightIndex+1]) >= targetValue){
            count ++;
        }

        leftIndex++;
        rightIndex++;

    }while (rightIndex < arrSize);


    return count;
}