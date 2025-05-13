#include<stdio.h> // 包含标准输入输出库
#include<stdlib.h> // 包含标准库

// 定义一个结构体来存储游戏设置
typedef struct {
    float volume; // 音量
    int resolution_x; // 分辨率 X
    int resolution_y; // 分辨率 Y
    int difficulty; // 难度
}GameSettings;

// 函数声明：安全写入游戏设置到文件
void write_config_safe(const GameSettings * setting,const char *filename);
// 函数声明：安全从文件读取游戏设置
void read_config_safe( GameSettings*setting,const char *filename);

int main(void)
{
    // GameSettings setting={0.75,1920,1080,2}; // 注释掉的初始化设置
    // write_config_safe(&setting,"D:\\桌面11\\c读写\\08.bin"); // 注释掉的写入函数调用

    GameSettings setting; // 定义一个 GameSettings 结构体变量
    read_config_safe(&setting,"D:\\桌面11\\c读写\\08.bin"); // 调用读取游戏设置的函数
    // 打印读取到的游戏设置
    printf("音量：%.2f\n辨率：%dx%d\n难度：%d\n",
        setting.volume,
        setting.resolution_x,
        setting.resolution_y,
        setting.difficulty);

    return 0; // 返回成功状态码
}

// 安全写入游戏设置到文件函数实现
void write_config_safe(const GameSettings*setting,const char* filename)
{
    FILE*file=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("wb" 表示二进制写入，如果文件存在则清空，不存在则创建)
    errno_t err=fopen_s(&file,filename,"wb");
    // 检查文件是否成功打开
    if(err!=0||file==NULL)
    {
        perror("无法打开文件进行写入操作\n"); // 打印文件打开失败信息
        return; // 返回
    }
    // 使用 fwrite 将结构体数据写入文件
    // fwrite 函数：
    // 参数1: 指向要写入的数据的指针
    // 参数2: 每个数据项的大小（以字节为单位）
    // 参数3: 要写入的数据项的数量
    // 参数4: 文件流指针
    // 返回值: 成功写入的数据项数量
    fwrite(setting,sizeof(GameSettings),1,file);
    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(file);
    puts("写入成功\n"); // 打印写入成功的消息
}

// 安全从文件读取游戏设置函数实现
void read_config_safe(GameSettings*setting,const char*filename)
{
    FILE*file=NULL; // 文件指针，初始化为 NULL
    // 使用 fopen_s 安全地打开文件
    // 参数1: 文件指针的地址
    // 参数2: 文件路径
    // 参数3: 打开模式 ("rb" 表示二进制读取)
    errno_t err=fopen_s(&file,filename,"rb");
    // 检查文件是否成功打开
    if(err!=0||file==NULL)
    {
        perror("无法打开文件进行读取操作\n"); // 打印文件打开失败信息
        return; // 返回
    }
    // 使用 fread 从文件读取结构体数据
    // fread 函数：
    // 参数1: 存储读取数据的缓冲区指针
    // 参数2: 每个数据项的大小（以字节为单位）
    // 参数3: 要读取的数据项的数量
    // 参数4: 文件流指针
    // 返回值: 成功读取的数据项数量
    fread(setting,sizeof(GameSettings),1,file);
    // 关闭文件流
    // fclose 函数：
    // 参数1: 文件流指针
    // 返回值: 成功时返回 0，失败时返回 EOF
    fclose(file);
}

/*
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
参数
ptr -- 这是指向要被写入的元素数组的指针。
size -- 这是要被写入的每个元素的大小，以字节为单位。
nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。

*/