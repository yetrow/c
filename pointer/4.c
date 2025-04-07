//数组作为函数参数
#include<stdio.h>

int sum(int *a,int size)
{
    int i,sum=0;
    printf("函数中sizeof(a)的值是%d,sizeof(a[0])的值是%d\n",sizeof(a),sizeof(a[0]));
    for(int i=0;i<size;i++)         //数组是通过一段连续的地址来存放各个元素
    {
        sum+=a[i];
    }
    return sum;
}

int main(void)
{
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    int total=sum(a,size);
    printf("sizeof(a)的值是%d,sizeof(a[0])的值是%d\n",sizeof(a),sizeof(a[0]));
    printf("数组的和是%d\n",total);
    return 0;
}