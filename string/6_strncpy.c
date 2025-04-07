#include<stdio.h>
#include<string.h>

// strncpy_s函数是一个安全的字符串拷贝函数，用于将源字符串的前n个字符拷贝到目标字符串中。

int main(void)
{
    char dest[20];
    const char *src="hellow world";

    size_t max_copy=10;
    errno_t result=strncpy_s(dest,sizeof(dest),src,max_copy);//将src的内容拷贝到dest中，最多拷贝max_copy个字符，注意dest的大小要足够容纳拷贝后的字符串
    //如果函数成功执行，它通常会返回 0。
    //如果函数执行过程中发生错误（例如，参数无效、目标缓冲区太小等），它会返回一个非零的错误码
    
    if(result==0)
    {
        printf("字符串dest是%s\n",dest);
    }
    else
    {
        printf("字符串dest存储失败\n");
    }
    return 0;
}