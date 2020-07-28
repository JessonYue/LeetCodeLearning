//
// Created by Jesson on 2020/7/14.
//
#include <cstdio>

int binarySearch(int* arr, int left, int right, int val);
int binarySearch(int a[], int n, int key);

int main()
{
    int arr[10]={1,3,4,5,8,9,10,15,26,30};
    int val=10;
    int left=0;
    int right=sizeof(arr)/sizeof(arr[0])-1;
//    int p=binarySearch(arr,left,right,val);
   int p =  binarySearch(arr,10,11);
    printf("%d",p);
}

int binarySearch(int* arr, int start, int end, int val) {
    int mid=(start+end)/2;
    if(start<end)
    {
        if(arr[mid]==val)
            return mid;
        else if(arr[mid]>val)
            return binarySearch(arr,start,mid,val);
        else
            return binarySearch(arr,mid+1,end,val);
    }
    else
        return -1;
}

int binarySearch(int a[], int n, int key)
{
    int  low, high, mid;
    low = 1;						//return 0 代表找不到，所以从最低下标从 1 开始
    high = n;					//定义最高下标为记录末位

    while (low <= high)
    {
        mid = (low + high)/2;		//折半
        if (key < a[mid])			//若查找值比中值小
        {
            high = mid - 1;			//最高下标调整到中位下标小一位
        }
        else if (key > a[mid])		//若查找值比中值大
        {
            low = mid + 1;			//最低下标调整到中位下标大一位
        }
        else
        {
            return mid;				//若相等则说明mid即为查找到的位置
        }
    }
    return 0;					//返回0，即没有找到  所以low从下标1开始
}