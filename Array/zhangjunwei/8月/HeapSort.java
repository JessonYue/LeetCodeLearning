package com.lanfairy.md.eight;

public class HeapSort {
    public void test(){
        int[] array=new int[]{2,3,4,5,6,7,1,8,9};
        heapSort(array,array.length);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]+" ");
        }

    }
    /**
     * 调整堆
     */
    void maxHeapify(int array[],int start,int end){
        //父亲的位置
        int dad=start;
        //儿子的位置
        int son=dad*2+1;
        while(son<=end){//如果子节点下标在可以调整的范围内就一直调整下去
            //如果没有右孩子就不用比,有的话,比较两个儿子，选择最大的出来
            if(son+1 <= end && array[son]<array[son+1]){
                son++;
            }
            //和父节点比大小
            if(array[dad]>array[son]){
                return;
            }else{//父亲比儿子小，就要对整个子树进行调整
                int temp=array[son];
                array[son]=array[dad];
                array[dad]=temp;
                //递归下一层
                dad=son;
                son=dad*2+1;
            }
        }
    }
    void heapSort(int array[],int len){
        //建堆  len/2-1最后一个非叶子节点
        for(int i=len/2-1;i>=0;i--){
            maxHeapify(array,i,len-1);
        }
        //排序,根节点和最后一个节点交换
        //换完以后，取走根，重新建堆
        //len-1 最后一个节点
        for(int i=len-1;i>0;i--){
            int temp=array[0];
            array[0]=array[i];
            array[i]=temp;
            maxHeapify(array,0,i-1);
        }
    }
}
