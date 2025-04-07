#include<stdio.h>
#include<string.h>

// strncat_s函数是一个安全的字符串连接函数，用于将源字符串的前n个字符连接到目标字符串的末尾。
// 注意目标字符串的大小要足够容纳连接后的字符串，且目标字符串必须以'\0'结尾。

int main(void)
{
    char dest[50]="0";
    strcpy_s(dest,sizeof(dest),"hello");
    const char *src=",world";

    size_t max_append=5;
    int res=strncat_s(dest,sizeof(dest),src,max_append);
    if(res==0)
    {
        printf("%s\n",dest);
    }
    else
    {
        printf("error\n");
    }
    return 0;
}