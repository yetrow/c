#include<stdio.h>
#include<string.h>

// strstr()函数用于查找字符串中第一次出现指定子字符串的位置
// strcasestr()函数用于查找字符串中第一次出现指定子字符串的位置，忽略大小写

 int main(void)
{
    const char*text="this is an example from english";
    const char *sub ="an";

    char *res=strstr(text,sub);

    if(res != NULL)
    {
        printf("found \" %s \" in \" %s \" ,at位置%td\n",sub,text,res-text+1);
    }
    else{
        puts("没有找到\n");
    }


    return 0;
}