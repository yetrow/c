#include<stdio.h>
#include"game_struct.h"
#include"game_function.h"

int main(void)
{
	puts("欢迎来到游戏世界!\n");

	Player player;
	create_player(&player, "Hero", Warrior);
	print_player_info(&player);
}