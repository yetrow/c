#include <stdio.h> // 包含标准输入输出库
#include <stdlib.h> // 包含标准库，用于 EXIT_FAILURE 和 EXIT_SUCCESS
#include <errno.h> // 包含 errno 定义，用于错误处理

int main(void) {
    FILE* file_stream = NULL; // 文件指针，初始化为 NULL
    char buffer[256]; // 缓冲区，用于存储读取的文本行

    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("r" 表示只读)
    errno_t err = fopen_s(&file_stream, "D:\\桌面11\\1.txt", "r");

    // 检查文件是否成功打开
    if (err != 0 || file_stream == NULL) {
        perror("Failed to open file111"); // 打印错误信息
        return EXIT_FAILURE; // 返回失败状态码
    }

    // 第一次读取：使用 fgets 按行读取文件内容
    // fgets 函数：
    // 参数1: 存储读取内容的缓冲区
    // 参数2: 缓冲区的大小（包括终止 null 字符的空间）
    // 参数3: 文件流指针
    // 返回值: 成功时返回缓冲区指针，到达文件末尾或发生错误时返回 NULL
    while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
        printf("%s", buffer); // 打印读取到的文本行
    }
    printf("\n"); // 打印换行符，分隔两次读取的输出

    rewind(file_stream); // 重置文件位置指示器到文件开头

    // 第二次读取：使用 fgetc 按字符读取文件内容
    int ch; // 用于存储读取到的字符
    // fgetc 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回读取到的字符（转换为 int），到达文件末尾或发生错误时返回 EOF
    while ((ch = fgetc(file_stream)) != EOF) {
        putchar(ch); // 打印读取到的字符
    }

    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    if (fclose(file_stream) != 0) {
        perror("Error closing file"); // 打印关闭文件时的错误信息
        return EXIT_FAILURE; // 返回失败状态码
    }

    return EXIT_SUCCESS; // 返回成功状态码
}