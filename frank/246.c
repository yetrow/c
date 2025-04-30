//函数指针和callback回调函数
#include<stdio.h>

typedef void (*call)(int);

void add(int a){
    printf("%d\n",a);
}

int main(void)
{
    call a=add;
    a(25);

    return 0;
}

