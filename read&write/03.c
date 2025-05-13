#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 EXIT_FAILURE

int main(void)
{
    FILE* file_ptr=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("r+" 表示读写，文件必须存在)
    errno_t err =fopen_s(&file_ptr,"D:\\桌面11\\c读写\\1.txt","r+");  
    // 检查文件是否成功打开
    if(err!=0||file_ptr==NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err); // 打印错误代码
        return EXIT_FAILURE; // 返回失败状态码
    }
    
    // 使用 ftell 获取当前文件位置
    // 参数1: 文件流指针
    // 返回值: 成功时返回当前文件位置（以字节为单位），失败时返回 -1L
    long position=ftell(file_ptr);
    printf("当前位置%ld\n",position); // 打印当前文件位置
    
    char buffer[256]; // 缓冲区，用于存储读取的文本行
    // 使用 fgets 按行读取文件内容
    // fgets 函数：
    // 参数1: 存储读取内容的缓冲区
    // 参数2: 缓冲区的大小（包括终止 null 字符的空间）
    // 参数3: 文件流指针
    // 返回值: 成功时返回缓冲区指针，到达文件末尾或发生错误时返回 NULL
    if(fgets(buffer,sizeof(buffer),file_ptr)!=NULL)
    {
        printf("读取的内容: %s\n", buffer); // 打印读取到的文本行
        position=ftell(file_ptr);//获取当前位置
        printf("当前位置%ld\n",position); // 打印读取后的文件位置
    }
    
    // 使用 fseek 移动文件位置指示器
    // 参数1: 文件流指针
    // 参数2: 偏移量
    // 参数3: 起始位置 (SEEK_SET: 文件开头, SEEK_CUR: 当前位置, SEEK_END: 文件末尾)
    // 返回值: 成功时返回 0，失败时返回非零值
    fseek(file_ptr,0,SEEK_SET);//将文件指针移动到文件开头
    printf("使用fseek后位置%ld\n",ftell(file_ptr)); // 打印使用 fseek 后的文件位置

    // 使用 rewind 重置文件位置指示器到文件开头
    // 参数1: 文件流指针
    rewind(file_ptr);
    printf("使用rewind后位置%ld\n",ftell(file_ptr)); // 打印使用 rewind 后的文件位置


    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(file_ptr);
    return 0; // 返回成功状态码

}