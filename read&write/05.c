#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 EXIT_FAILURE
#include<errno.h> // 包含 errno 定义，用于错误处理


int main(void)
{
    FILE* stream=NULL; // 文件指针，初始化为 NULL
    // long l; // 注释掉的变量
    // float fp; // 注释掉的变量
    // char s[81]; // 注释掉的变量
    // char c; // 注释掉的变量

    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("w+" 表示读写，如果文件存在则清空，不存在则创建)
    errno_t err=fopen_s(&stream,"D:\\桌面11\\c读写\\1.txt","w+");
    // 检查文件是否成功打开
    if(err!=0||stream==NULL)
    {
        printf("打开文件失败\n"); // 打印文件打开失败信息
        return EXIT_FAILURE; // 返回失败状态码
    }

    int id=1; // 定义一个 int 变量
    float temp=36.5f; // 定义一个 float 变量
    char name[20]="tom"; // 定义一个字符串
    char grade='a'; // 定义一个 char 变量

    // 使用 fprintf 向文件写入格式化数据
    // 参数1: 文件流指针
    // 参数2: 格式字符串
    // 参数3: 要写入的变量
    // 返回值: 成功时返回写入的字符数，失败时返回负值
    fprintf(stream,"id=%d\n",id); // 写入 id

    fprintf(stream,"temp=%.1f\n",temp); // 写入 temp，保留一位小数
    fprintf(stream,"name=%s\n",name); // 写入 name
    fprintf(stream,"grade=%c\n",grade); // 写入 grade

    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    if(fclose(stream)!=0)
    {
        perror("关闭文件失败\n"); // 打印关闭文件时的错误信息
        return EXIT_FAILURE; // 返回失败状态码
    };//只涉及到读可以不写

    puts("写入成功\n"); // 打印写入成功的消息


    return 0; // 返回成功状态码

}