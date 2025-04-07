//函数传值vs传引用
#include<stdio.h>

void func(int*p)
{
    *p=(*p)+1;
}

int main(void)
{
    int a=10;
    func(&a);
    printf("a=%d",a);
}