#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库，用于 EXIT_FAILURE

int main(void)
{
    FILE *source_file,*target_file; // 源文件和目标文件指针
    char *source_path="D:\\桌面11\\c读写\\09.txt"; // 源文件路径
    char *target_path="D:\\桌面11\\c读写\\09_1.txt"; // 目标文件路径

    char buffer[1024]; // 缓冲区，用于存储读取的数据

    size_t bytes_read; // 存储每次读取的字节数
    // 使用 fopen_s 安全地打开源文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("rb" 表示二进制读取)
    errno_t err=fopen_s(&source_file,source_path,"rb");
    // 检查源文件是否成功打开
    if(err!=0||source_file==NULL)
    {
        perror("无法打开源文件\n"); // 打印错误信息
        return EXIT_FAILURE; // 返回失败状态码
    }

    // 使用 fopen_s 安全地打开目标文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("wb" 表示二进制写入，如果文件存在则清空，不存在则创建)
    err=fopen_s(&target_file,target_path,"wb");
    // 检查目标文件是否成功打开
    if(err!=0||target_file==NULL) // 注意：这里应该检查 target_file 是否为 NULL，而不是 target_path
    {
        perror("无法打开目标文件\n"); // 打印错误信息 (此处错误信息应为“无法打开目标文件”)
        // 在实际应用中，如果目标文件打开失败，应该先关闭已成功打开的源文件
        fclose(source_file); 
        return EXIT_FAILURE; // 返回失败状态码
    }

    // 循环读取源文件并写入目标文件
    // fread 函数：
    // 参数1: 存储读取数据的缓冲区指针
    // 参数2: 每个数据项的大小（以字节为单位）
    // 参数3: 要读取的数据项的数量
    // 参数4: 文件流指针
    // 返回值: 成功读取的数据项数量
    // fwrite 函数：
    // 参数1: 指向要写入的数据的指针
    // 参数2: 每个数据项的大小（以字节为单位）
    // 参数3: 要写入的数据项的数量
    // 参数4: 文件流指针
    // 返回值: 成功写入的数据项数量
    while((bytes_read=fread(buffer,1,sizeof(buffer),source_file))>0)
    {
        fwrite(buffer,1,bytes_read,target_file); // 将读取到的数据写入目标文件
    }
    
    // 关闭所有打开的文件
    // _fcloseall 函数：
    // 返回值: 成功关闭的文件流数量
    _fcloseall();
    puts("复制成功\n"); // 打印复制成功的消息
    return 0; // 返回成功状态码
}