#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 EXIT_FAILURE
#include<errno.h> // 包含 errno 定义，用于错误处理

int main(void)
{
    FILE *stream=NULL; // 文件指针，初始化为 NULL
    char buffer[100]; // 缓冲区，用于存储读取的文本行

    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("r+" 表示读写，文件必须存在)
    errno_t err =fopen_s(&stream,"D:\\桌面11\\c读写\\1.txt","r+");

    // 检查文件是否成功打开
    if(err!=0||stream==NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err); // 打印错误代码
        return EXIT_FAILURE; // 返回失败状态码
    }

    // 使用 fgets 按行读取文件内容直到文件末尾
    // fgets 函数：
    // 参数1: 存储读取内容的缓冲区
    // 参数2: 缓冲区的大小（包括终止 null 字符的空间）
    // 参数3: 文件流指针
    // 返回值: 成功时返回缓冲区指针，到达文件末尾或发生错误时返回 NULL
    while(fgets(buffer,sizeof(buffer),stream)!=NULL)
    {
        printf("读取的内容: %s\n", buffer); // 打印读取到的文本行
    }

    // 检查文件读取是否发生错误
    // ferror 函数：
    // 参数1: 文件流指针
    // 返回值: 如果设置了文件的错误指示器，则返回非零值，否则返回零
    if(ferror(stream)){
        puts("读取文件发生错误\n"); // 打印读取错误信息
        clearerr(stream); // 清除文件错误指示器和文件结束指示器
    }
    
    // 检查是否到达文件末尾
    // feof 函数：
    // 参数1: 文件流指针
    // 返回值: 如果设置了文件的文件结束指示器，则返回非零值，否则返回零
    if(feof(stream))
    {
        puts("到达文件末尾\n"); // 打印到达文件末尾信息
    }
    else{
        puts("没有到达文件末尾\n"); // 打印未到达文件末尾信息
    }

    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(stream);
    return 0; // 返回成功状态码
}