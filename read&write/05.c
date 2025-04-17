#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


int main(void)
{
    FILE* stream=NULL;
    // long l;
    // float fp;
    // char s[81];
    // char c;

    errno_t err=fopen_s(&stream,"D:\\桌面11\\c读写\\1.txt","w+");
    if(err!=0||stream==NULL)
    {
        printf("打开文件失败\n");
        return EXIT_FAILURE;
    }

    int id=1;
    float temp=36.5f;
    char name[20]="tom";
    char grade='a';

    fprintf(stream,"id=%d\n",id);

    fprintf(stream,"temp=%.1f\n",temp);
    fprintf(stream,"name=%s\n",name);
    fprintf(stream,"grade=%c\n",grade);

    if(fclose(stream)!=0)
    {
        perror("关闭文件失败\n");
        return EXIT_FAILURE;
    };//只涉及到读可以不写

    puts("写入成功\n");


    return 0;

}