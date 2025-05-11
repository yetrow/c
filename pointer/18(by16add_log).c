//realloc和多级指针的应用
//基于16.c添加log
#include<stdio.h> // 包含标准输入输出库，用于printf, fprintf等函数
#include<stdlib.h> // 包含标准库，用于realloc, EXIT_SUCCESS等函数
#include<string.h> // 包含字符串处理库，用于snprintf等函数
#include<errno.h> // 包含错误码库，虽然在此文件中未直接使用errno，但与错误处理相关
#include<time.h> // 包含时间日期库，用于获取当前时间

#define TIME_SIZE 26 // 定义时间字符串缓冲区大小

// 定义一个Player结构体，用于存储玩家信息
typedef struct{
    int id;         // 玩家ID
    char name[30];  // 玩家姓名
}Player;

// 函数原型声明
// updatePlayerlist: 更新玩家列表，可能需要重新分配内存并添加新玩家
// 参数:
//   players: 指向Player指针的指针，用于修改main函数中的players指针，实现动态内存管理
//   currentSize: 指向当前玩家数量的指针，用于修改main函数中的currentSize变量
//   newSize: 新的玩家数量，通常是currentSize + 1
//   newPlayer: 要添加的新玩家信息
void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer);
// printPlayers: 打印玩家列表信息
// 参数:
//   players: 指向Player数组（动态分配的内存块）的指针
//   size: 玩家数量
void printPlayers(Player*players,int size);

// 日志函数原型声明
// logError: 记录错误级别的日志
// 参数:
//   message: 错误信息字符串
void logError(const char*message);
// logInfo: 记录信息级别的日志
// 参数:
//   message: 信息字符串
void logInfo(const char*message);
// logMessage: 记录带时间戳和级别的日志信息到标准错误流
// 参数:
//   level: 日志级别字符串 (e.g., "INFO", "ERROR")
//   message: 日志信息字符串
void logMessage(const char*level,const char*message);

// 主函数
int main(void)
{
    Player* players=NULL;   // 玩家列表初始化为空指针，表示当前没有玩家
    int currentSize=0;      // 当前玩家数量初始化为0

    // 创建并添加第一个玩家
    Player newPlayer1={1,"player1"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer1);
    // 创建并添加第二个玩家
    Player newPlayer2={2,"player2"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer2);
    // 创建并添加第三个玩家
    Player newPlayer3={3,"player3"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer3);
    // 打印当前玩家列表
    printPlayers(players,currentSize);

    free(players); // 释放动态分配的内存，防止内存泄漏
    return EXIT_SUCCESS; // 程序成功退出
}

// 更新玩家列表函数实现
void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer)
{
    // 检查新大小是否小于当前大小，如果是则记录错误信息并返回
    if(newSize<*currentSize)
    {
        logError("error: newSize is less than currentSize");
        return;
    }
    // 检查新大小是否等于当前大小，如果是则记录信息并返回，因为新大小必须大于当前大小才能添加新玩家
    if(newSize==*currentSize)
    {
        logInfo("no resizing needed.the newSize must be greater than currentSize to add a new");
        return;
    }
    // 使用realloc尝试重新分配内存，将当前players指向的内存块大小调整为newSize * sizeof(Player)
    // realloc会尝试扩展现有内存块，如果无法扩展，则分配新的内存块并将现有内容复制过去
    Player*temp=realloc(*players,newSize*sizeof(Player));

    // 检查realloc是否成功
    if(temp==NULL)
    {
        logError("errno reallocating momeroy"); // realloc失败，记录错误信息
    }
    else{
        *players=temp; // realloc成功，更新main函数中的players指针指向新的内存块
        // 如果新大小大于当前大小（即添加了新空间），则在新分配的内存空间的末尾（原大小索引处）添加新玩家
        if(newSize>*currentSize)
        {
            (*players)[*currentSize]=newPlayer;
        }
        *currentSize=newSize; // 更新main函数中的当前玩家数量
        logInfo("player added successfully"); // 记录信息日志表示玩家添加成功
        char infoMessage[100]; // 定义一个缓冲区用于构建信息字符串
        // 使用snprintf格式化当前玩家数量信息到缓冲区
        snprintf(infoMessage,sizeof(infoMessage),"current player count:%d",*currentSize);
        logInfo(infoMessage); // 记录当前玩家数量信息日志
    }
}
// 打印玩家列表函数实现
void printPlayers(Player*players,int size)
{
    printf("current players:\n"); // 输出提示信息到标准输出
    // 遍历玩家列表并打印每个玩家的ID和姓名到标准输出
    for(size_t i=0;i<size;i++)
    {
        printf("ID:%d,Name:%s\n",players[i].id,players[i].name);
    }
}
// 记录错误级别日志函数实现
void logError(const char*message)
{
    logMessage("ERROR",message); // 调用logMessage函数，级别为"ERROR"
}
// 记录信息级别日志函数实现
void logInfo(const char*message)
{
    logMessage("INFO",message); // 调用logMessage函数，级别为"INFO"
}
// 记录带时间戳和级别的日志信息到标准错误流函数实现
void logMessage(const char*level,const char*message)
{
    time_t now=time(NULL); // 获取当前时间
    char timeStr[TIME_SIZE]; // 定义一个缓冲区用于存储时间字符串

    // 使用ctime_s安全地将时间转换为字符串
    if(ctime_s(timeStr,sizeof(timeStr),&now)==0)
    {
        // 如果转换成功，将时间、级别和消息格式化输出到标准错误流
        // 注意：ctime_s生成的字符串末尾包含换行符
        fprintf(stderr,"[%s %s: %s",timeStr,level,message);
    }
    else{
        // 如果转换失败，输出错误信息到标准错误流
        fprintf(stderr,"[error] failed to get current time\n");}

}
