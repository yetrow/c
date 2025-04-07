//sprintf
// sprintf_s函数是一个安全的字符串格式化函数，用于将格式化的数据写入字符串中。

#include<stdio.h>

int main(void)
{
    char butter[50]={0};
    int num=3;
    double pi=3.14159;

    int res=sprintf_s(butter,sizeof(butter),"num=%d,pi=%.2f",num,pi);//将格式化的字符串存储到 butter 中，注意 butter 的大小要足够容纳格式化后的字符串

    if(res>=0)
    {
        printf("字符串butter是%s\n",butter);
    }
    else
    {
        printf("字符串butter存储失败,错误代码:%d\n",res);
    }
    return 0; 
}