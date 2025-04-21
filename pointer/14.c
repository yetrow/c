//多级指针
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a=10;

    int* ptr=&a;

    int**pptr=&ptr;

    printf("a:%d\n",&a);        //a的地址
    printf("ptr:%d\n",ptr);     //ptr指针变量本身，是ptr指向a的地址
    printf("&ptr:%d\n",&ptr);   //ptr本身的地址
    printf("*ptr:%d\n",*ptr);   //访问ptr指向的地址，并取出那里的值
    puts("\n");
    printf("pptr:%d\n",pptr);   //pptr指针变量本身，是pptr指向ptr的地址
    printf("&pptr:%d\n",&pptr); //ptr本身的地址
    printf("*pptr:%d\n",*pptr); //访问 pptr 指向的内存地址，并取出那里的值
    printf("**pptr:%d\n",**pptr);


    return 0;

}