//
// Created by 张俊伟 on 2020/7/18.
//


#include <stdio.h>

void siftUpComparable(int *array, int k, int x) {
    while (k > 0) {
        //父亲的位置
        int parent = (k >> 1) - 1;
        if (array[parent]>x)
            return;
        array[k] = array[parent];
        k = parent;
    }
    array[k] = x;
}

void maxHeapify(int *array, int start, int end) {
    //父亲的位置
    int parent = start;
    //儿子的位置
    int child = (parent << 1) + 1;
    int target = array[parent];
    int index = parent;
    //如果子节点下标在可以调整的范围内就一直调整下去
    while (child <= end) {
        //如果没有右孩子就不用比,有的话,比较两个儿子，选择最大的出来
        if (child + 1 <= end && array[child] < array[child + 1])
            child++;
        //和父节点比大小
        if (array[child] < array[parent]) {
            return;
        } else {//父亲比儿子小，就要对整个子树进行调整
            int tmp = array[child];
            array[child] = array[parent];
            array[parent] = tmp;
            parent = child;
            child = (parent << 1) + 1;
        }
    }

}


void heapSort(int *array, int len) {
    //建堆  len/2-1最后一个非叶子节点
    for (int i = (len >> 1) - 1; i >= 0; i--) {
        maxHeapify(array, i, len - 1);
    }

    //排序,根节点和最后一个节点交换
    //换完以后，取走根，重新建堆
    //len-1 最后一个节点
    for (int i = len - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        maxHeapify(array, 0, i - 1);
    }
}

void test() {
    int array[] = {2, 3, 4, 5, 6, 7, 1, 8, 9};
    int len = 9;

    heapSort(array, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", array[i]);
    }

}

int main() {
    test();
    return 0;
}