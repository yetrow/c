#include<stdio.h>
#include<stdlib.h>

int* add(int *a,int *b)
{
    int c=(*a)+(*b);
    return &c;
}

int main(void)
{
    int a=1,b=2;
    int *ptr=add(&a,&b);
    printf("c=%d",*ptr);
    return 0;
}