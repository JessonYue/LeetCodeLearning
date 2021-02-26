//
// Created by Jesson on 2020/6/10.
//

#ifndef BASEDATASTRUCTURE_STACK_H
#define BASEDATASTRUCTURE_STACK_H


using namespace std;

template <class T>
struct stackNode
{
    T data;
    stackNode* next;
};


template <class T>
class myStack
{
public:
    myStack();
    ~myStack();
    void push(T data);
    void pop();
    T stackTop();
    bool isEmpty();
private:
    stackNode<T> * top; //对象
};

void test_stack();

#endif //BASEDATASTRUCTURE_STACK_H
