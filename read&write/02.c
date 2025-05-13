#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 EXIT_FAILURE
#include<errno.h> // 包含 errno 定义，用于错误处理
#include<string.h> // 包含字符串处理函数，如 memset (虽然在此文件中未直接使用，但在注释掉的代码中有)
#include<inttypes.h> // 包含固定宽度整数类型（在此文件中未直接使用）



int main(void)
{
    FILE* file_ptr = NULL; // 文件指针，初始化为 NULL
    const char* filename = "D:\\桌面11\\c读写\\1.txt"; // 要操作的文件名
    
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("w" 表示写入，如果文件存在则清空，不存在则创建)
    errno_t err = fopen_s(&file_ptr, filename, "w");
    // 检查文件是否成功打开
    if (err != 0 || file_ptr == NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err); // 打印错误代码
        perror("详细错误信息"); // 打印详细的系统错误信息
        printf("尝试打开的文件路径: %s\n", filename); // 打印尝试打开的文件路径
        return EXIT_FAILURE; // 返回失败状态码
    }
    
    // 使用 fputc 向文件写入单个字符
    // 参数1: 要写入的字符
    // 参数2: 文件流指针
    // 返回值: 成功时返回写入的字符，失败时返回 EOF
    fputc('a', file_ptr);
    
    // 使用 fputs 向文件写入字符串
    // 参数1: 要写入的字符串
    // 参数2: 文件流指针
    // 返回值: 成功时返回非负值，失败时返回 EOF
    fputs("how are you\n", file_ptr);

    double pi = 3.14; // 定义一个 double 变量
    // 使用 fprintf 向文件写入格式化数据
    // 参数1: 文件流指针
    // 参数2: 格式字符串
    // 参数3: 要写入的变量
    // 返回值: 成功时返回写入的字符数，失败时返回负值
    fprintf(file_ptr, "numers:%d,%lf,%s\n", 10, pi, "end of the examples\n");
    
    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    if (fclose(file_ptr) != 0) {
        perror("关闭文件时出错"); // 打印关闭文件时的错误信息
        return EXIT_FAILURE; // 返回失败状态码
    }

    puts("写入成功"); // 打印写入成功的消息
    return 0; // 返回成功状态码
}