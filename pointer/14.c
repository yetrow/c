//多级指针
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a=10;

    int* p=&a;

    int**ptr=&p;

    int***pptr=&ptr;

    printf("a:%d\n",&a);            //a的地址
    printf("p:%d\n",p);             //p指针变量本身，是p指向a的地址
    printf("&p:%d\n",&p);           //p本身的地址
    printf("*p:%d\n",*p);           //访问p指向的地址，并取出那里的值，即a的值
    puts("\n");
    printf("ptr:%d\n",ptr);         //ptr指针变量本身，是ptr指向p的地址
    printf("&ptr:%d\n",&ptr);       //ptr本身的地址
    printf("*ptr:%d\n",*ptr);       //访问 ptr 指向的内存地址p，并取出p地址
    printf("**ptr:%d\n",**ptr);
    puts("\n");
    printf("pptr:%d\n",pptr);       //pptr指针变量本身，是pptr指向ptr的地址
    printf("&pptr:%d\n",&pptr);     //pptr本身的地址
    printf("*pptr:%d\n",*pptr);     //访问pptr指向的地址（即 ptr 的地址），取出该地址上的值（即 ptr 的值，也就是 p 的地址）
    printf("**pptr:%d\n",**pptr);


    return 0;

}