//strlen的用法

#include<stdio.h>
#include<string.h>

int main(void)
{
    char dest[50]="hello";
    printf("%zu\n",strlen(dest));//第二个参数是 size_t 类型（这是 sizeof 运算符返回的类型，通常是 unsigned long 或 unsigned long long）
    // %zu输出 size_t型。size_t在库中定义为unsigned int。
    return 0;
}

/*  char dest[50]={0};
    strcpy_s(dest,50,"hello");  **相当于strlen之前用strcpy_s检查一下
    printf("%zu\n",dest);
*/