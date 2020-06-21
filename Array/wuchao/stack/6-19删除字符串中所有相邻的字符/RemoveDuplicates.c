#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
// Created by 吴超 on 2020/6/19.
//
typedef struct Node{
    char value;
    struct Node* next;
} Node;
Node* createNode(char x);
typedef struct {
    Node* head;
    int size;
} MyStack;
MyStack* myStackCreate();
void myStackPush(MyStack* obj, char x);
char myStackPop(MyStack* obj);
char myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);

Node* createNode(char x){
    Node* node = malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    return node;
}

MyStack* myStackCreate(){
    MyStack* myStack = malloc(sizeof(MyStack));
    myStack->head = createNode(-1);
    myStack->size = 0;
    return myStack;
}

bool myStackEmpty(MyStack* obj){
    return obj->head->next == NULL;
}

void myStackPush(MyStack* obj, char x){
    Node* node = createNode(x);
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

char myStackPop(MyStack* obj){
    if(myStackEmpty(obj)){
        return -1;
    }
    char top = myStackTop(obj);
    obj->head = obj->head->next;
    obj->size--;
    return top;
}

char myStackTop(MyStack* obj){
    return obj->head->value;
}

char * removeDuplicates(char * S){
    MyStack* myStack = myStackCreate();
    unsigned long stringLength = strlen(S);
    unsigned long i=0;
    while (i<stringLength){
        char item = S[i];
        if(myStackEmpty(myStack)){
            myStackPush(myStack,item);
        } else {
            if(myStackTop(myStack)==item){
                myStackPop(myStack);
            } else {
                myStackPush(myStack,item);
            }
        }
        i++;
    }
    int stackLength = myStack->size;
    i = 0;
    while(i<stackLength){
        S[stackLength-i-1] = myStackPop(myStack);
        i++;
    }
    if(i<stringLength){
        S[i] = 0;
    }
    return S;
}

//简便解法，利用栈的思想，将字符串当成一个栈来使用，top记录栈顶元素，writeIndex记录栈顶元素在数组的下标(覆盖的字符串的哪个位置)
//依次遍历字符串每个字符，如果和栈顶元素相等，则writeIndex减1，则代表栈顶元素出栈了，如果栈为空即writeIndex为0或者，栈顶元素和遍历的元素不相等
//则入栈，即将字符数组下标writeIndex的元素复制为遍历的元素。直到遍历完整个字符数组。将栈顶后面的一个元素赋值为0，代表字符串结束。返回字符串即可。
char * removeDuplicates2(char * S){
    unsigned long stringLength = strlen(S);
    unsigned long i=0;
    char top = 0;
    int writeIndex = 0;
    while(i<stringLength){
        if(writeIndex==0){
            top = 0;
        } else {
            top = S[writeIndex-1];
        }
        if(top==S[i]){
            writeIndex--;
        }else{
            S[writeIndex++] = S[i];
        }
        i++;
    }
    S[writeIndex] = 0;
    return S;
}
