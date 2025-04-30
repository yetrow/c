#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[10]={0,1,2,3,4,5,6,7,8};
    int*p=a;
    int**ptr=&p;

    printf("%d\n",p[5]);         //5
    printf("%d\n",(*ptr)[5]);    //5

    return 0;
}