//指向指针的指针
#include<stdio.h>
int main(void)
{
    int x=5;
    int *p=&x;
    int**q=&p;
    int***r=&q;
    printf("*p是%d\n",*p);
    printf("*q是%d\n",*q);
    printf("**q是%d\n",**q);
    printf("**r是%d\n",**r);
    printf("***r是%d\n",***r);
    ***r=10;
    printf("x是%d\n",x);

    **q=*p+2;
    printf("x=%d",x);
    return 0;
}