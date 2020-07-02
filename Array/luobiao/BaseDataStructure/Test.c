//
// Created by Jesson on 2020/6/23.
//

int printf(const char* format, ...);

void func1(int i);

int global_int_var = 84;
int global_unint_var;

void fun1(int i);

void fun1(int i)
{
    printf("%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;

    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);
}

