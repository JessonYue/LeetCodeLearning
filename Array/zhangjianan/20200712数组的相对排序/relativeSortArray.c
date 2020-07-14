int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int arr[1001]={0};
    int i,j=0;
    for(i=0;i<arr1Size;i++){//记录arr1数字出现的次数次数
        arr[arr1[i]]++;
    }
    for(i=0;i<arr2Size;i++){//找到在arr2和arr1都出现的数字
        while(arr[arr2[i]]>0){
            arr1[j]=arr2[i];
            j++;
            arr[arr2[i]]--;
        }
    }
    for(i=0;i<1001;i++){//找arr1有，arr2没有的
        while(arr[i]>0){
            arr1[j++]=i;
            arr[i]--;
        }
    }
    *returnSize=arr1Size;
    return arr1;

}
int main() {
    int arr1[11]={2,3,1,3,2,4,6,7,9,2,19};
    int arr2[6]={2,1,4,3,9,6};
    int a[11];
    int * arr=relativeSortArray(arr1,sizeof(arr1)/sizeof(int),arr2,sizeof(arr2)/sizeof(int),a);
    for (int i = 0; i <11; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}