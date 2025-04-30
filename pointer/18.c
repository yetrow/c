//realloc和多级指针的应用
//基于16.c添加log
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>

#define TIME_SIZE 26


typedef struct{
    int id;
    char name[30];
}Player;

void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer);
void printPlayers(Player*players,int size);

void logError(const char*message);
void logInfo(const char*message);
void logMessage(const char*level,const char*message);

int main(void)
{
    Player* players=NULL;   //玩家列表初始化为空
    int currentSize=0;      //当前玩家数量

    Player newPlayer1={1,"player1"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer1);
    Player newPlayer2={2,"player2"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer2);
    Player newPlayer3={3,"player3"};
    updatePlayerlist(&players,&currentSize,currentSize+1,newPlayer3);
    printPlayers(players,currentSize);

    free(players);
    return EXIT_SUCCESS;
}

void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer)
{
    if(newSize<*currentSize)
    {
        logError("error");
        return;
    }
    if(newSize==*currentSize)
    {
        logInfo("no resizing needed.the newSize must be greater than currentSize to add a new");
        return;
    }
    Player*temp=realloc(*players,newSize*sizeof(Player));
    
    if(temp==NULL)
    {
        logError("errno reallocating momeroy");
    }
    else{
        *players=temp;
        if(newSize>*currentSize)
        {
        (*players)[*currentSize]=newPlayer;
        }
        *currentSize=newSize;
        logInfo("player added successfully");
        char infoMessage[100];
        snprintf(infoMessage,sizeof(infoMessage),"current player count:%d",*currentSize);
        logInfo(infoMessage);
    }
}
void printPlayers(Player*players,int size)
{
    printf("current players:\n");
    for(size_t i=0;i<size;i++)
    {
        printf("ID:%d,Name:%s\n",players[i].id,players[i].name);
    }
}
void logError(const char*message)
{
    logMessage("INFO",message);
}
void logInfo(const char*message)
{
    logMessage("INFO",message);
}
void logMessage(const char*level,const char*message)
{
    time_t now=time(NULL);
    char timeStr[TIME_SIZE];

    if(ctime_s(timeStr,sizeof(timeStr),&now)==0)
    {
        fprintf(stderr,"[%s] %s: %s\n",timeStr,level,message);
    }
    else{
        fprintf(stderr,"[error] failed to get current time\n");}

}
