#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[]="hello";
    char*p=str;

    p[1]='a';
    printf("%s\n",str);

    while(*p!='\0')
    {
        printf("%c",*p);
        p++;
    }

    return 0;
}