#include<stdio.h>
#include<string.h>


// strcmp()函数用于比较两个字符串的大小关系
// strncmp()函数用于比较两个字符串的前n个字符的大小关系

int main(void)
{
    const char* str1="hello,world";
    const char* str2="hello,world";
    const char* str3="hello gays";

    if(strcmp(str1,str2)==0)
    {
        puts("相等\n");
    }
    else
    {
        puts("不相等\n");
    }

    size_t num=7;
    if(strncmp(str1,str3,num)==0)
    {
        puts("相等\n");
    }
    else
    {
        puts("不相等\n");
    }

    return 0;
}