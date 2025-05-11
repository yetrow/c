//realloc和多级指针的应用
#include<stdio.h> // 包含标准输入输出库，用于printf等函数
#include<stdlib.h> // 包含标准库，用于realloc和EXIT_SUCCESS等函数
#include<string.h> // 包含字符串处理库，虽然在此文件中未使用，但通常与字符串操作相关

// 定义一个Player结构体，用于存储玩家信息
typedef struct{
    int id;         // 玩家ID
    char name[30];  // 玩家姓名
}Player;

// 函数原型声明
// updatePlayerlist: 更新玩家列表，可能需要重新分配内存
// 参数:
//   players: 指向Player指针的指针，用于修改main函数中的players指针
//   currentSize: 指向当前玩家数量的指针，用于修改main函数中的currentSize变量
//   newSize: 新的玩家数量
//   newPlayer: 要添加的新玩家信息
void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer);
// printPlayers: 打印玩家列表信息
// 参数:
//   players: 指向Player数组的指针
//   size: 玩家数量
void printPlayers(Player*players,int size);

// 主函数
int main(void)
{
    Player* players=NULL;   // 玩家列表初始化为空指针
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

    free(players); // 释放动态分配的内存
    return EXIT_SUCCESS; // 程序成功退出
}

// 更新玩家列表函数实现
void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer)
{
    // 检查新大小是否小于当前大小，如果是则输出错误信息并返回
    if(newSize<*currentSize)
    {
        puts("error\n");
        return;
    }
    // 检查新大小是否等于当前大小，如果是则输出信息并返回，因为新大小必须大于当前大小才能添加新玩家
    if(newSize==*currentSize)
    {
        puts("no resizing needed.the newSize must be greater than currentSize to add a new\n");
        return;
    }
    // 使用realloc尝试重新分配内存，将当前players指向的内存块大小调整为newSize * sizeof(Player)
    // realloc会尝试扩展现有内存块，如果无法扩展，则分配新的内存块并将现有内容复制过去
    Player*temp=realloc(*players,newSize*sizeof(Player));

    // 检查realloc是否成功
    if(temp==NULL)
    {
        printf("errno reallocating momeroy\n"); // realloc失败，输出错误信息
    }
    else{
        *players=temp; // realloc成功，更新main函数中的players指针指向新的内存块
        (*players)[*currentSize]=newPlayer; // 在新分配的内存空间的末尾（原大小索引处）添加新玩家
        *currentSize=newSize; // 更新main函数中的当前玩家数量
    }
}
// 打印玩家列表函数实现
void printPlayers(Player*players,int size)
{
    printf("current players:\n"); // 输出提示信息
    // 遍历玩家列表并打印每个玩家的ID和姓名
    for(size_t i=0;i<size;i++)
    {
        printf("ID:%d,Name:%s\n",players[i].id,players[i].name);
    }
}
