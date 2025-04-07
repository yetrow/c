#include<stdio.h>
#include<string.h>


// strtok_s()函数用于分割字符串，返回分割后的子字符串
// strtok_s()函数是线程安全的版本，strtok()函数不是线程安全的

int main(void)
{
    char str[]="hello,this is frank's channel!";
    char deli[]=" ";
    char*token;
    char*context={0};

    token=strtok_s(str,deli,&context);

    while(token!=NULL)
    {
        printf("token is %s\n",token);
        token=strtok_s(str,deli,&context);
    }
    return 0;

}