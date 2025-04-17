#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE* file_ptr=NULL;
    errno_t err =fopen_s(&file_ptr,"D:\\桌面11\\c读写\\1.txt","r+");  
    if(err!=0||file_ptr==NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err);
        return EXIT_FAILURE;
    }
    long position=ftell(file_ptr);
    printf("当前位置%ld\n",position);
    
    char buffer[256];
    if(fgets(buffer,sizeof(buffer),file_ptr)!=NULL)
    {
        printf("读取的内容: %s\n", buffer);
        position=ftell(file_ptr);//获取当前位置
        printf("当前位置%ld\n",position);
    }
    
    fseek(file_ptr,0,SEEK_SET);//将文件指针移动到文件开头
    printf("使用fseek后位置%ld\n",ftell(file_ptr));

    rewind(file_ptr);
    printf("使用rewind后位置%ld\n",ftell(file_ptr));


    fclose(file_ptr);
    return 0;

}