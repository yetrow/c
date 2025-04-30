#ifndef GAME_FUNCTION_H
#define GAME_FUNCTION_H

#include "game_struct.h"

void create_player(Player* player, const char* name, CharacterClass);
Enemy generateEnemy(EnemyType type, int32_t level);
void battle(Player* player, Enemy* enemy);
void print_player_info(const Player* player);
void print_enemy_info(const Enemy* enemy);



#endif