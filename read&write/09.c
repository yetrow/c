#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *source_file,*target_file;
    char *source_path="D:\\桌面11\\c读写\\09.txt";
    char *target_path="D:\\桌面11\\c读写\\09_1.txt";

    char buffer[1024];

    size_t bytes_read;
    errno_t err=fopen_s(&source_file,source_path,"rb");
    if(err!=0||source_file==NULL)
    {
        perror("无法打开源文件\n");
        return EXIT_FAILURE;
    }

    err=fopen_s(&target_file,target_path,"wb");
    if(err!=0||target_path==NULL)
    {
        perror("无法打开源文件\n");
        return EXIT_FAILURE;
    }

    while((bytes_read=fread(buffer,1,sizeof(buffer),source_file))>0)
    {
        fwrite(buffer,1,bytes_read,target_file);
    }
    _fcloseall();
    puts("复制成功\n");
    return 0;
}