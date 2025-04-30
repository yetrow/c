#include<stdio.h>

typedef enum{
    attack,
    move,
    count           //记录事件的总数
}EventType;

typedef void(*Event)(const char* playerName);

Event events[count];
/*
声明了一个数组，这个数组每一个元素都是Event类型的函数指针
意味着每个数组元素都可以存储一个指向函数的指针，这个函数复合Event的
签名，它接受一个const char* 的参数类型，并且返回void
*/
//注册事件处理函数
void registerEvent(EventType type,Event hand);
//分发事件
void dispatchEvent(EventType type,const char* playerName);

void playerattack(const char* playerName);
void playermove(const char* playerName);

int main(void)
{
    registerEvent(attack,playerattack);
    registerEvent(move,playermove);

    dispatchEvent(attack,"jack");
    dispatchEvent(move,"tom");

    return 0;
}

void registerEvent(EventType type,Event hand)
{
    if(type<count){
        events[type]=hand;
    }
}
void dispatchEvent(EventType type,const char* playerName)
{
    if(events[type]!=NULL)
    {
        events[type](playerName);
    }
}

void playerattack(const char* playerName)
{
    printf("%s attack\n",playerName);
}
void playermove(const char* playerName)
{
    printf("%s moves!\n",playerName);
}