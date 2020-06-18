//
// Created by 吴超 on 2020/6/16.
//
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char value;
    struct Node* next;
} Node;
Node* createNode(char x);
typedef struct {
    Node* head;
} MyStack;
MyStack* myStackCreate();
void myStackPush(MyStack* obj, char x);
char myStackPop(MyStack* obj);
char stackTop(MyStack* obj);
bool isEmpty(MyStack* obj);

Node* createNode(char x){
    Node* node = malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    return node;
}

MyStack* myStackCreate(){
    MyStack* myStack = malloc(sizeof(MyStack));
    myStack->head = createNode(0);
    return myStack;
}

bool isEmpty(MyStack* obj){
    return obj->head->next == NULL;
}

void myStackPush(MyStack* obj, char x){
    Node* node = createNode(x);
    node->next = obj->head;
    obj->head = node;
}

char myStackPop(MyStack* obj){
    if(isEmpty(obj)){
       return 0;
    }
    char top = stackTop(obj);
    obj->head = obj->head->next;
    return top;
}

char stackTop(MyStack* obj){
    return obj->head->value;
}

bool isLeft(char a);
bool isMatch(char a,char b);
bool isValid(char * s){
    int length = strlen(s);
    if(length%2!=0) return false;
    MyStack* stack = myStackCreate();
    int i=0;
    while (i<length){
        char item = s[i];
        if(isLeft(item)){
            myStackPush(stack,item);
        } else {
            if(isEmpty(stack)){
                return false;
            }
            if(isMatch(stackTop(stack),item)){
               myStackPop(stack);
            } else {
                return false;
            }
        }
        i++;
    }
    if(isEmpty(stack)){
        return true;
    }
    return false;
}

bool isMatch(char a,char b){
    if(a=='{') return b=='}';
    if(a=='[') return b==']';
    if(a=='(') return b==')';
    return false;
}

bool isLeft(char a){
    return a=='{'||a=='['||a=='(';
}


