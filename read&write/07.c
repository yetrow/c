#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 exit 和 EXIT_FAILURE
#include<errno.h> // 包含 errno 定义，用于错误处理
#include<string.h> // 包含字符串处理函数，如 strerror_s

// 函数声明：安全读取配置文件
void read_config_safe(const char *filename);
// 函数声明：安全追加日志到文件
void append_log_safe(const char *filename,const char*str);
// 函数声明：清空日志文件
void clear_log(const char *filename);

int main(void)
{
    const char *filename="D:\\桌面11\\c读写\\1.txt"; // 配置文件名
    read_config_safe(filename); // 调用读取配置文件的函数

    const char *log_name="D:\\桌面11\\c读写\\log.txt"; // 日志文件名
    const char *str="hello world\n"; // 要写入日志的字符串
    append_log_safe(log_name,str); // 调用追加日志的函数

    //clear_log(log_name); // 注释掉的清空日志函数调用

    // 关闭所有打开的文件
    // _fcloseall 函数：
    // 返回值: 成功关闭的文件流数量
    int numclosed=_fcloseall();//关闭所有打开的文件(保险操作)
    printf("关闭的文件数: %d\n",numclosed); // 打印关闭的文件数量

    return 0; // 返回成功状态码
}

// 安全读取配置文件函数实现
void read_config_safe(const char *filename)
{
    FILE *file_ptr=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("r" 表示只读)
    errno_t err=fopen_s(&file_ptr,filename,"r");
    // 检查文件是否成功打开
    if(err!=0||file_ptr==NULL)
    {
        char errno_msg[256]; // 缓冲区用于存储错误信息
        // 使用 strerror_s 获取错误码对应的错误信息
        // 参数1: 存储错误信息的缓冲区
        // 参数2: 缓冲区大小
        // 参数3: 错误码
        strerror_s(errno_msg,sizeof(errno_msg),err);
        // 打印详细的错误信息到标准错误流
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, errno_msg);
        exit(EXIT_FAILURE); // 退出程序并返回失败状态码
    }

    char buffer[256]; // 缓冲区，用于存储读取的文本行
    // 使用 fgets 按行读取文件内容直到文件末尾
    // fgets 函数：
    // 参数1: 存储读取内容的缓冲区
    // 参数2: 缓冲区的大小（包括终止 null 字符的空间）
    // 参数3: 文件流指针
    // 返回值: 成功时返回缓冲区指针，到达文件末尾或发生错误时返回 NULL
    while(fgets(buffer,sizeof(buffer),file_ptr)!=NULL)
    {
        printf("%s",buffer); // 打印读取到的文本行
    }
    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(file_ptr);
}

// 安全追加日志到文件函数实现
void append_log_safe(const char *filename,const char*str)
{
    FILE *file_ptr=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("a+" 表示追加读写，如果文件不存在则创建，写入从文件末尾开始)
    errno_t err=fopen_s(&file_ptr,filename,"a+");
    // 检查文件是否成功打开
    if(err!=0||file_ptr==NULL)
    {
        char errno_msg[256]; // 缓冲区用于存储错误信息
        // 使用 strerror_s 获取错误码对应的错误信息
        // 参数1: 存储错误信息的缓冲区
        // 参数2: 缓冲区大小
        // 参数3: 错误码
        strerror_s(errno_msg,sizeof(errno_msg),err);
        // 打印详细的错误信息到标准错误流
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, errno_msg);
        exit(EXIT_FAILURE); // 退出程序并返回失败状态码
    }
    // 使用 fprintf 向文件写入格式化数据
    // 参数1: 文件流指针
    // 参数2: 格式字符串
    // 参数3: 要写入的变量
    // 返回值: 成功时返回写入的字符数，失败时返回负值
    fprintf(file_ptr,"%s",str); // 写入字符串到文件
    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    if(fclose(file_ptr)!=0)
    {
        perror("关闭文件失败\n"); // 打印关闭文件时的错误信息
        exit(EXIT_FAILURE); // 退出程序并返回失败状态码
    }
}

// 清空日志文件函数实现
void clear_log(const char *filename)
{
    FILE*file_ptr=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("w" 表示写入，如果文件存在则清空，不存在则创建)
    errno_t err=fopen_s(&file_ptr,filename,"w");
    // 检查文件是否成功打开
    if(err!=0||file_ptr==NULL)
    {
        char buffer[256]; // 缓冲区用于存储错误信息
        // 使用 strerror_s 获取错误码对应的错误信息
        // 参数1: 存储错误信息的缓冲区
        // 参数2: 缓冲区大小
        // 参数3: 错误码
        strerror_s(buffer,sizeof(buffer),err);
        // 打印详细的错误信息到标准错误流
        fprintf(stderr,"打开文件失败，错误代码: %d, 错误信息: %s\n", err, buffer);
        exit(EXIT_FAILURE); // 退出程序并返回失败状态码
    }
    // 关闭文件流 (以 "w" 模式打开并立即关闭会清空文件内容)
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(file_ptr);
}