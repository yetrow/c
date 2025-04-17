#include<stdio.h>
#include<stdlib.h>

typedef struct {
    float volume;
    int resolution_x;
    int resolution_y;
    int difficulty;
}GameSettings;

void write_config_safe(const GameSettings * setting,const char *filename);
void read_config_safe( GameSettings*setting,const char *filename);

int main(void)
{
    // GameSettings setting={0.75,1920,1080,2};
    // write_config_safe(&setting,"D:\\桌面11\\c读写\\08.bin");

    GameSettings setting;
    read_config_safe(&setting,"D:\\桌面11\\c读写\\08.bin");
    printf("音量：%.2f\n辨率：%dx%d\n难度：%d\n",
        setting.volume,
        setting.resolution_x,
        setting.resolution_y,
        setting.difficulty);



    return 0;
}

void write_config_safe(const GameSettings*setting,const char* filename)
{
    FILE*file=NULL;
    errno_t err=fopen_s(&file,filename,"wb");
    if(err!=0||file==NULL)
    {
        perror("无法打开文件进行写入操作\n");
        return;
    }
    fwrite(setting,sizeof(GameSettings),1,file);
    fclose(file);
    puts("写入成功\n");
}

void read_config_safe(GameSettings*setting,const char*filename)
{
    FILE*file=NULL;
    errno_t err=fopen_s(&file,filename,"rb");
    if(err!=0||file==NULL)
    {
        perror("无法打开文件进行读取操作\n");
        return;
    }
    fread(setting,sizeof(GameSettings),1,file);
    fclose(file);
}

/*
ize_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
参数
ptr -- 这是指向要被写入的元素数组的指针。
size -- 这是要被写入的每个元素的大小，以字节为单位。
nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。

*/