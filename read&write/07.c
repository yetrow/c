#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void read_config_safe(const char *filename);
void append_log_safe(const char *filename,const char*str);
void clear_log(const char *filename);

int main(void)
{
    const char *filename="D:\\桌面11\\1.txt";
    read_config_safe(filename);

    const char *log_name="D:\\桌面11\\log.txt";
    const char *str="hello world\n";
    append_log_safe(log_name,str);

    clear_log(log_name);

    int numclosed=_fcloseall();//关闭所有打开的文件(保险操作)
    printf("关闭的文件数: %d\n",numclosed);

    return 0;
}

void read_config_safe(const char *filename)
{
    FILE *file_ptr=NULL;
    errno_t err=fopen_s(&file_ptr,filename,"r");
    if(err!=0||file_ptr==NULL)
    {
        char errno_msg[256];
        strerror_s(errno_msg,sizeof(errno_msg),err);
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, errno_msg);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while(fgets(buffer,sizeof(buffer),file_ptr)!=NULL)
    {
        printf("%s",buffer);
    }
    fclose(file_ptr);
}

void append_log_safe(const char *filename,const char*str)
{
    FILE *file_ptr=NULL;
    errno_t err=fopen_s(&file_ptr,filename,"a+");
    if(err!=0||file_ptr==NULL)
    {
        char errno_msg[256];
        strerror_s(errno_msg,sizeof(errno_msg),err);
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, errno_msg);
        exit(EXIT_FAILURE);
    }
    fprintf(file_ptr,"%s",str);
    if(fclose(file_ptr)!=0)
    {
        perror("关闭文件失败\n");
        exit(EXIT_FAILURE);
    }
}

void clear_log(const char *filename)
{
    FILE*file_ptr=NULL;
    errno_t err=fopen_s(&file_ptr,filename,"w");
    if(err!=0||file_ptr==NULL)
    {
        char buffer[256];
        strerror_s(buffer,sizeof(buffer),err);
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, buffer);
        exit(EXIT_FAILURE);
    }
    fclose(file_ptr);
}