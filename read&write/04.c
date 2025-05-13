// crt_fscanf_s.c
// This program writes formatted
// data to a file. It then uses fscanf to
// read the various data back from the file.

#include <stdio.h> // 包含标准输入输出库
#include <stdlib.h> // 包含标准库

FILE *stream; // 文件指针

int main( void )
{
   long l; // 用于存储从文件读取的 long 类型数据
   float fp; // 用于存储从文件读取的 float 类型数据
   char s[81]; // 缓冲区，用于存储从文件读取的字符串
   char c; // 用于存储从文件读取的单个字符

   // 使用 fopen_s 安全地打开文件
   // 参数1: 文件指针的地址
   // 参数2: 文件路径
   // 参数3: 打开模式 ("r" 表示只读)
   errno_t err = fopen_s( &stream, "D:\\桌面11\\c读写\\1.txt", "r" );
   // 检查文件是否成功打开
   if( err )
      printf_s( "The file fscanf.out was not opened\n" ); // 打印文件打开失败信息
   else
   {
    // 使用 fscanf_s 从文件读取格式化数据
    // fscanf_s 函数：
    // 参数1: 文件流指针
    // 参数2: 格式字符串
    // 后续参数: 存储读取数据的变量的地址，对于字符串和字符，需要额外提供缓冲区大小
    // 返回值: 成功匹配并赋值的输入项的数量，如果在任何转换发生之前到达文件末尾或发生读取错误，则返回 EOF
    if(fscanf_s(stream,"%80s",s,(unsigned)_countof(s))!=1) // 读取字符串，限制最大宽度为 80，并提供缓冲区大小
    {
        printf("读取字符串失败\n"); // 打印读取字符串失败信息
    }
    if(fscanf_s(stream,"%lds",&l)!=1) // 读取 long 类型数据
    {
        printf("读取ld失败\n"); // 打印读取 long 失败信息
    }
    if(fscanf_s(stream,"%f",&fp)!=1) // 读取 float 类型数据
    {
        printf("读取lf失败\n"); // 打印读取 float 失败信息
    }
    if(fscanf_s(stream," %c",&c,1)!=1) // 读取单个字符，注意格式字符串前的空格会跳过空白字符
    {
        printf("读取c失败\n"); // 打印读取字符失败信息
    }


      // 输出读取到的数据
      printf( "%s\n", s );
      printf( "%ld\n", l );
      printf( "%f\n", fp );
      printf( "%c\n", c );

      // 关闭文件流
      // fclose 函数：
      // 参数1: 文件流指针
      // 返回值: 成功时返回 0，失败时返回 EOF
      fclose( stream );
   }
   return 0; // 返回成功状态码
}