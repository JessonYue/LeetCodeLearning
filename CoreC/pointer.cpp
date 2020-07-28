#include <iostream>

using namespace std;
int change(int b)
{
    b=10;
    return b;
}
int change(int *b)
{
    *b=10;
    return *b;
}
int main()
{
//    int a=5;
//    change(a);
//    cout<<a<<endl;//输出5
//    int c=0;
//    c=change(a);
//    cout<<c<<endl;//输出10
//========通过指针操作
    int a=5;
    int *p=&a;
    change(p);
    cout<<a<<endl;//输出10
    int c=0;
    c=change(p);
    cout<<c<<endl;//输出10
}
//我们需要修改对变量的修改权限 这个时候需要指针

