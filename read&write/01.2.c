#include<stdio.h>
#include<stdlib.h>
#include<errno.h>



int main(void)
{
    FILE* file_stream=NULL;
    char buffer[256];
    errno_t err=fopen_s(&file_stream,"D:\\桌面11\\1.txt","r");

    if(err!=0||file_stream==NULL)
    {
        perror("failed to open file\n");
        return EXIT_FAILURE;
    }

    while(fgets(buffer,sizeof(buffer),file_stream)!=NULL)
{
    printf("%s\n",buffer);

}
    rewind(file_stream);

    int ch;
    while((ch=fgetc(file_stream))!=EOF)
    {
        putchar(ch);
    }
    



}