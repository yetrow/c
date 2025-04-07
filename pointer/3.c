//指针和数组
#include<stdio.h>
int main(void)
{
    int a[]={2,4,6,8,10};
    int i;
    int *p=a;

    for(int i=0;i<5;i++)
    {
        printf("地址是%d\n",&a[i]);
        printf("地址是%d\n",a+i);
        printf("值是%d\n",a[i]);
        printf("值是%d\n",*(a+i));
    }
    
    return 0;
}