#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// strch()函数用于查找字符串中第一次出现指定字符的位置
// strrchr()函数用于查找字符串中最后一次出现指定字符的位置

int main(void)
{
    char str[] = "hello worldw";

    char find1 = 'w';
    char* ptr_char = strchr(str, find1);

    if (ptr_char)
    {
        printf("找到了%c的位置是:%td\n", find1, ptr_char - str + 1);
    }

    char* ptr_char1 = strrchr(str, find1);

    if (ptr_char1)
    {
        printf("找到了%c的位置是:%td\n", find1, ptr_char1-str+1);
    }

    system("pause");
    return 0;

}