//realloc和多级指针的应用
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char name[30];
}Player;

void updatePlayerlist(Player**players,int*currentSize,int newSize,Player newPlayer);
void printPlayers(Player*players,int size);

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
        puts("error\n");
        return;
    }
    if(newSize==*currentSize)
    {
        puts("no resizing needed.the newSize must be greater than currentSize to add a new\n");
        return;
    }
    Player*temp=realloc(*players,newSize*sizeof(Player));
    
    if(temp==NULL)
    {
        printf("errno reallocating momeroy\n");
    }
    else{
        *players=temp;
        (*players)[*currentSize]=newPlayer;
        *currentSize=newSize;
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
