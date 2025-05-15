//多级指针
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a=10;

    int* p=&a; //定义一个指向int类型的指针p，指向a的地址

    int**ptr=&p; //定义一个指向int*类型的指针ptr，指向p的地址

    int***pptr=&ptr; //定义一个指向int**类型的指针pptr，指向ptr的地址

    printf("a:%d\n",&a);            //a的地址100
    printf("p:%d\n",p);             //p指针变量本身，是p指向a的地址100
    printf("&p:%d\n",&p);           //p本身的地址200
    printf("*p:%d\n",*p);           //访问p指向的地址，并取出那里的值，即a的值10
    puts("\n");
    printf("ptr:%d\n",ptr);         //ptr指针变量本身，是ptr指向p的地址200
    printf("&ptr:%d\n",&ptr);       //ptr本身的地址300
    printf("*ptr:%d\n",*ptr);       //访问 ptr 指向的内存地址p，并取出p地址100
    printf("**ptr:%d\n",**ptr);     // 打印ptr指针所指向的指针所指向的整数值10
    puts("\n");
    printf("pptr:%d\n",pptr);       //pptr指针变量本身，是pptr指向ptr的地址200
    printf("&pptr:%d\n",&pptr);     //pptr本身的地址400
    printf("*pptr:%d\n",*pptr);     //访问pptr指向的地址（即 ptr 的地址），取出该地址上的值（即 ptr 的值，也就是 p 的地址）200
    printf("**pptr:%d\n",**pptr);   // 打印pptr指针所指向的指针所指向的整数值100


    return 0;

}