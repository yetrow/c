#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<inttypes.h>



int main(void)
{
    FILE* file_ptr = NULL;
    const char* filename = "D:\\桌面11\\1.txt";
    
    errno_t err = fopen_s(&file_ptr, filename, "w");
    if (err != 0 || file_ptr == NULL)
    {
        printf("打开文件失败，错误代码: %d\n", err);
        perror("详细错误信息");
        printf("尝试打开的文件路径: %s\n", filename);
        return EXIT_FAILURE;
    }
    
    fputc('a', file_ptr);
    fputs("how are you\n", file_ptr);

    double pi = 3.14;
    fprintf(file_ptr, "numers:%d,%lf,%s\n", 10, pi, "end of the examples\n");
    
    if (fclose(file_ptr) != 0) {
        perror("关闭文件时出错");
        return EXIT_FAILURE;
    }

    puts("写入成功");
    return 0;
}