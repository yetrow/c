#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a,int b);
int (*myFunctionPointer)(int,int);

int main(void)
{
    myFunctionPointer=add;
    int result=myFunctionPointer(2,3);

    printf("%d",result);
}

int add(int a,int b)
{
    return a+b;
}