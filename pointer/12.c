#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char *name;
    int level;
    int hp;
}Character;

Character* create_character(const char*name,int level,int hp);
void free_character(Character*character);
void print_character(const Character* character);

int main(void)
{     
    Character*hero=create_character("hello",1,100);
    if(hero==NULL)
    {
        return EXIT_FAILURE;
    }
    
    print_character(hero);

    free_character(hero);
    return EXIT_SUCCESS; 
}

Character* create_character(const char*name,int level,int hp)
{
    Character*new_character=(Character*)malloc(sizeof(Character));

    if(new_character==NULL)
    {
        perror("failed to allocate memory for new character");
        return NULL;
    }

    new_character->name=(char*)malloc(strlen(name)+1);

    if(new_character->name==NULL)
    {
        perror("failed to allocate memory for new character");
        free(new_character);    //防止内存泄漏
        return NULL;
    }

    strcpy_s(new_character->name,strlen(name)+1,name);
    new_character->level=level;
    new_character->hp=hp;

    return new_character;
}

void free_character(Character*character)
{
    if(character!=NULL)
    {
        free(character->name);
        free(character);
    }
}

void print_character(const Character* character)  // ✅ 新增打印函数
{
    if (character != NULL)
    {
        printf("Name: %s\n", character->name);
        printf("Level: %d\n", character->level);
        printf("HP: %d\n", character->hp);
    }
}