#include<stdio.h>
//初识字符串
#include<string.h> //strlen, strcpy, strcat, strcmp等函数的头文件


int main(void)
{
    const char arr[]="hello world"; //用数组定义字符串，字符串常量存储在只读数据区，不能修改
    printf("%s\n",arr);

    const char *p="hello"; //用指针定义一般不能修改字符串的内容
    //因为"hello"是一个字符串常量，存储在只读数据区，所以不能修改。
    //p[0]='H'; //error: assignment of read-only location '*(p + 0)'
    printf("%s\n",p);

    return 0;
}



