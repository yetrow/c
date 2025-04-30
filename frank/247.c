//函数指针和callback回调函数
#include<stdio.h>

typedef void(*Callback)(int);

void traverse(int* array,int size,Callback callback);
void printElement(int element);
void doubleElement(int element);

int main(void)
{
    int numbers[]={1,2,3,4,5};
    int size=sizeof(numbers)/sizeof(numbers[0]);

    //实现模块化
    traverse(numbers,size,printElement);
    traverse(numbers,size,doubleElement);

    return 0;
}
//回调函数：将一个函数传递给另一个函数，可以在后者中调用前者函数
//将一个函数作为参数传入另一个函数，在该函数内部调用这个参数函数
void traverse(int *array,int size ,Callback callback)
{
    for(int i=0;i<size;i++)
    {
        callback(array[i]);
    }
}

void printElement(int element)
{
    printf("%d\n",element);
}
void doubleElement(int element)
{
    printf("%d doubled is %d\n",element,element*2);
}