#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int *a=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;i++)
    {
        a[i]=i+1;
    }

    int *b=(int*)realloc(a,20*sizeof(int));
    for(int i=0;i<20;i++)
    {
        printf("%d ",b[i]);
    }

    return 0;
}