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
