//指针与字符串数组
#include<stdio.h>

void print(char *c)
{
    c[0]='a';
    while(*c!='\0')
    {
        printf("%c\n",*c);
        c++;
    }
    puts("\n");
}

int main(void)
{
    char c[20]="hello world";
    print(c);

    return 0;
}