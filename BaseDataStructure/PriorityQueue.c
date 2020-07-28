//
// Created by Jesson on 2020/6/11.
//
#include <MacTypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


#define MinData (-32767)
#define MinPQSize (10)

typedef int ElementType;

/*最小堆*/
typedef struct HeapStruct {
    int Capacity; //最大容量
    int Size; //当前大小
    ElementType *Elements; //元素数组
}PriorityQueue;

PriorityQueue* init(int MaxElements);
void destroy(PriorityQueue* H);
void makeEmpty(PriorityQueue* H);
int isEmpty(PriorityQueue* H);
int isFull(PriorityQueue* H);
void insert(ElementType X, PriorityQueue* H);
ElementType deleteMin(PriorityQueue* H);
ElementType findMin(PriorityQueue* H);


PriorityQueue*
init(int MaxElements){
    PriorityQueue* H;

    if(MaxElements < MinPQSize){
        printf("Priority queue size is too small");
        exit(-1);
    }

    H = malloc(sizeof(PriorityQueue));
    if(H == NULL){
        printf("failed to alloc memory space for HeapStruct");
        exit(-1);
    }

    H->Elements = malloc( (MaxElements+1) * sizeof(ElementType));
    if(H->Elements == NULL){
        printf("failed to allocate memory for Elements array");
        exit(-1);
    }

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData; //此处设置哨兵
    return H;
}
void
destroy(PriorityQueue* H){
    free(H->Elements);
    free(H);
}

void
makeEmpty(PriorityQueue* H){
    H->Size = 0;
}

void insert(ElementType X, PriorityQueue* H){
    int i;

    if(isFull(H)){
        printf("Priority queue is full");
        return;
    }

    //从尾部向头部检查
    for(i=++H->Size; H->Elements[i/2]>X; i/=2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = X;
}

ElementType
deleteMin(PriorityQueue* H){
    int i,Child;
    ElementType MinElement, LastElement;

    if(isEmpty(H)){
        printf("FATAL: Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for(i=1; i * 2 <= H->Size; i=Child){
        /*Find smaller child*/
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
            Child++;

        /*Percolate one level */
        //此时最后一个元素已经在堆顶部了，头部与最后一个元素交换过了
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;

    return MinElement;
}

ElementType
findMin(PriorityQueue* H){
    if(!isEmpty(H))
        return H->Elements[1];
    printf("FATAL: Priority queue is Empty");
    return H->Elements[0];
}

int
isEmpty(PriorityQueue* H){
    return H->Size == 0;
}

int
isFull(PriorityQueue* H){
    return H->Size == H->Capacity;
}
int main(){
    int i, NUM=30;
    PriorityQueue* pq = init(NUM);
    for(i=0; i<NUM; i++)
        insert(i, pq);

    while(!isEmpty(pq)){
        i = deleteMin(pq);
        printf("%d\n", i);
    }
    destroy(pq);
    return 0;
}