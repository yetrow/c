//回调函数（函数指针）
#include<stdio.h>
#include<stdlib.h>


int add(int a,int b)
{
    return a+b;
}

int main(void)
{
    int c;
    int(*p)(int,int);
    p=add;          //p=&add;
    c=p(2,3);                //c=(*p)(2,3);
    printf("%d",c);

    return 0;
}