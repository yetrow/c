//stract用法

//strcat函数用于将一个字符串连接到另一个字符串的末尾。

#include<stdio.h>
#include<string.h>

int main(void)
{
    char dest[50]="hello";
    const char *src=",world";

    //strcat(dest,src); //将src连接到dest后面，dest的内容变为helloworld

    int dest_size=sizeof(dest)-strlen(dest)-1; //dest_size是dest剩余的空间大小，-1是为了留出结束符'\0'的空间
    strcat_s(dest,dest_size,src); //将src连接到dest后面，dest的内容变为helloworld


    printf("%s\n",dest);
    return 0;
}