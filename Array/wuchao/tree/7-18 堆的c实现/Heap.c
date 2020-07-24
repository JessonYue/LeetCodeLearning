//
// Created by 吴超 on 2020/7/16.
//
#include <stdlib.h>
#include <stdio.h>

#define BIG_TOP_HEAP 0
#define SMALL_TOP_HEAP 1
#define AS 0
#define DS 1

typedef struct Heap {
    int *data;
    int capacity;
    int size;
    int type;
} Heap;

Heap *makeHeap(int initCapacity, int type);
Heap *makeHeapFromArray(int* source,int length, int type);

void heapify(Heap* heap);

void grow(Heap* heap);

void add(Heap *heap, int val);

void removeVal(Heap *heap, int val);

void swap(int *data, int a, int b);

void shiftUp(Heap *heap,int i);

void shiftDown(Heap *heap,int i);

int choose(Heap *heap,int a,int b);

void sort(int** source,int length,int type);

void printArray(int* data,int size);

void grow(Heap* heap){
    int newCapacity = 2* heap->capacity;
    int* oldArray = heap->data;
    heap->data = malloc(newCapacity*sizeof(int));
    for(int i=0;i<heap->size;i++){
        heap->data[i] = oldArray[i];
    }
    heap->capacity = newCapacity;
}

Heap *makeHeap(int initCapacity, int type) {
    Heap *heap = malloc(sizeof(Heap));
    heap->data = calloc(initCapacity, sizeof(int));
    heap->type = type;
    heap->size = 0;
    heap->capacity = initCapacity;
    return heap;
}

Heap *makeHeapFromArray(int* source,int length, int type){
    Heap * heap = malloc(sizeof(Heap));
    heap->data = malloc(length*sizeof(int));
    heap->type = type;
    heap->size = length;
    heap->capacity = length;
    for(int i=0;i<length;i++){
        heap->data[i] = source[i];
    }
    heapify(heap);
    return heap;
}

void heapify(Heap* heap){
    for(int i=(heap->size>>1)-1;i>=0;i--){
        shiftDown(heap,i);
    }
}

void sort(int** source,int length,int type){
    int heapType = BIG_TOP_HEAP;
    if(type==AS){
        heapType = BIG_TOP_HEAP;
    } else {
        heapType = SMALL_TOP_HEAP;
    }
    Heap* heap = makeHeapFromArray(*source,length,heapType);
    while(heap->size>0){
        swap(heap->data,0,heap->size-1);
        heap->size--;
        shiftDown(heap,0);
    }
    for(int i=0;i<length;i++){
        (*source)[i] = heap->data[i];
    }
}

void add(Heap *heap, int val) {
    if (heap->size >= heap->capacity) {
        //todo grow
        grow(heap);
    }
    heap->data[heap->size++] = val;
    int i = heap->size-1;
    shiftUp(heap,i);
}

void removeVal(Heap *heap, int val){
    if(heap->size<=0){
        return;
    }
    int i = 0;
    for(;i<heap->size;i++){
        if(heap->data[i]==val){
            break;
        }
    }
    if(heap->data[i]!=val){
        return;
    }
    if(i==heap->size-1){
        heap->data[heap->size--] = 0;
        return;
    }
    swap(heap->data,i,heap->size-1);
    heap->data[heap->size--] = 0;
    int moved = heap->data[i];
    shiftDown(heap,i);
    //说明这个元素向下堆化没有动，则向上堆化
    if(moved == heap->data[i]){
        shiftUp(heap,i);
    }
}

void shiftUp(Heap *heap, int i) {
    int parent = (i - 1) >> 1;
    while (parent >= 0 && heap->type == BIG_TOP_HEAP ?
    heap->data[parent] < heap->data[i] :
    heap->data[parent] > heap->data[i]) {
        swap(heap->data, parent, i);
        i = parent;
        parent = (i - 1) >> 1;
    }
}

void shiftDown(Heap * heap,int i){
    int half = heap->size>>1;
    while(i<half){
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        int child = rightChild<heap->size?choose(heap,leftChild,rightChild):leftChild;
        if(heap->type == BIG_TOP_HEAP){
            if(heap->data[i]<heap->data[child]){
                swap(heap->data,i,child);
                i = child;
            } else {
                break;
            }
        } else {
            if(heap->data[i]>heap->data[child]){
                swap(heap->data,i,child);
                i = child;
            } else {
                break;
            }
        }
    }
}

int choose(Heap *heap,int a,int b){
    if(heap->type == BIG_TOP_HEAP){
        if(heap->data[a]>heap->data[b]){
            return a;
        } else {
            return b;
        }
    } else {
        if(heap->data[a]<heap->data[b]){
            return a;
        } else {
            return b;
        }
    }
}


void swap(int *data, int a, int b) {
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void printArray(int* data,int size){
    for(int i=0;i<size;i++){
        printf("%d\n",data[i]);
    }
    printf("-----------\n");
}

int main(){
    int array[] = {234,532,31,23,5,7,-1,43,12,56};
    int* a = array;
    sort(&a,10,AS);
    printArray(a,10);
    Heap* heap = makeHeapFromArray(a,10,BIG_TOP_HEAP);
    printArray(heap->data,heap->size);
    add(heap,70);
    printArray(heap->data,heap->size);
    add(heap,44);
    printArray(heap->data,heap->size);
    removeVal(heap,234);
    printArray(heap->data,heap->size);
}




