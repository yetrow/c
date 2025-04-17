#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(void)
{
    FILE *stream=NULL;
    char buffer[100];

    errno_t err =fopen_s(&stream,"D:\\桌面11\\c读写\\1.txt","r+");

    if(err!=0||stream==NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err);
        return EXIT_FAILURE;
    }

    while(fgets(buffer,sizeof(buffer),stream)!=NULL)
    {
        printf("读取的内容: %s\n", buffer);
    }

    if(ferror(stream)){
        puts("读取文件发生错误\n");
        clearerr(stream);
    }
    if(feof(stream))
    {
        puts("到达文件末尾\n");
    }
    else{
        puts("没有到达文件末尾\n");
    }

    fclose(stream);
    return 0;
}