//练习函数指针的使用
#include<stdio.h>
#include<inttypes.h>

typedef int32_t(*operation_t)(int32_t,int32_t);

/*
typedef 为基本数据结构创建别名
    typedef uint32_t u32;
    u32 number=1;
这样我们就可以用u32来代替uint32_t
*/

int32_t add(int32_t a,int32_t b);
int32_t subtract(int32_t a,int32_t b);
int32_t multiply(int32_t a,int32_t b);
int32_t divide(int32_t a,int32_t b);

operation_t operations[4]={add,subtract,multiply,divide};

int main(void)
{
    int32_t a=10,b=5;
    int32_t result=0;

    result=operations[0](a,b);
    printf("%d\n",result);
    result=operations[1](a,b);
    printf("%d\n",result);
    result=operations[2](a,b);
    printf("%d\n",result);
    result=operations[3](a,b);
    printf("%d\n",result);

    return 0;
}

int32_t add(int32_t a,int32_t b){
    return a+b;
}
int32_t subtract(int32_t a,int32_t b){
    return a-b;
}
int32_t multiply(int32_t a,int32_t b){
    return a*b;
}
int32_t divide(int32_t a,int32_t b){
    if(b==0){
        printf("error\n");
        return 0;
    }
    return a/b;
}
