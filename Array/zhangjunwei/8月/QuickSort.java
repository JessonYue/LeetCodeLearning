package com.lanfairy.md.eight;

public class QuickSort {
    //快速排序     31  21  59  68  12  40
    //    x=31
    public static void quickSort(int[] array,int begin,int end){
        if(end-begin<=0) return;
        int x=array[begin];
        int low=begin;//0
        int high=end;//5
        //由于会从两头取数据，需要一个方向
        boolean direction=true;
        L1:
        while(low<high){
            if(direction){//从右往左找
                for(int i=high;i>low;i--){
                    if(array[i]<=x){
                        array[low++]=array[i];
                        high=i;
                        direction=!direction;
                        continue L1;
                    }
                }
                high=low;//如果上面的if从未进入，让两个指针重合
            }else{
                for(int i=low;i<high;i++){
                    if(array[i]>=x){
                        array[high--]=array[i];
                        low=i;
                        direction=!direction;
                        continue L1;
                    }
                }
                low=high;
            }
        }
        //把最后找到的值 放入中间位置
        array[low]=x;
        //开始完成左右两边的操作
        quickSort(array,begin,low-1);
        quickSort(array,low+1,end);
    }


    public void addition_isCorrect() throws Exception {
        int[] array=new int[]{1,7,4,9,3,2,6,5,8};
        int key=35;
        quickSort(array,0,array.length-1);

//        System.out.println(binarySearch(array,0,array.length,key));
        for (int i : array) {
            System.out.print(i+" ");
        }
    }
}
