#include<stdio.h>

int add(int a,int b)
{
    return a+b;
}

int main(void)
{
    typedef int(*p)(int,int);
//在这段代码中，typedef int(*p)(int, int); 
//定义了一个新的类型别名 p，表示一个指向接受两个 int 参数并返回 int 的函数的指针类型。
//此时 p 是一个类型名，不是变量名 。
    p a=add;
    int c;
    c=a(2,3);
    printf("%d\n",c);
}