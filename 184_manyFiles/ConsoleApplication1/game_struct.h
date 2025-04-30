#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

#include "game_types.h"
#include "game_abilities.h"

typedef struct {
	char name[50];
	CharacterClass char_class;
	Ability ability;
	int32_t level;
	int32_t health;
	int32_t experience;
}Player;

typedef struct {
	EnemyType type;
	Ability ability;
	int32_t level;
	int32_t health;
	int32_t experience;
}Enemy;

typedef struct {
	char name[50];
	ItemType type;
	int32_t power;
}Item;


#endif