//
// Created by Jesson on 2020/6/10.
//

#include <cstdio>
#include "Stack.h"

template <class T>
myStack<T>::myStack(){
    //printf("%d\n",top);
    top = NULL;
    //printf("%d\n",top);
}

template<class T>
myStack<T>::~myStack<T>() {
    stackNode<T> * node = NULL;
    while (top != NULL)
    {
        node = top;
        top = top->next;
        delete node;
    }
}

template <class T>
void myStack<T>::push(T data){
    stackNode<T>* node = new stackNode<T>;
    node->data = data;
    node->next = top; //赋值
    top = node;
}
template <class T>
void myStack<T>::pop(){
    stackNode<T>* node = top;
    top = top->next;
    delete node;
}

template <class T>
bool myStack<T>::isEmpty(){
    return top == NULL;
}

template <class T>
T myStack<T>::stackTop() {
    return top->data;
}

void test_stack(){
    myStack<int>* s = new myStack<int>;
    for (int i = 0 ;i < 10; i++)
    {
        s->push(i);
        printf("%d\n",i);
    }
    printf("\n");
    while (!s->isEmpty()) {
        int i = s->stackTop();
        printf("%d\n", i);
        s->pop();
    }
}

int main(){
    test_stack();
}