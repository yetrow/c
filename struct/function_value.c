#include<stdio.h>

void fun(int*a);

int main()
{
    int a = 4;
    fun(&a);
    printf("%d",a);
    return 0;
}

void fun(int*a)
{
    *a+=2;
}
