#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int hp;
    int attack;
} Player;

typedef struct {
    int x;
    int y;
    int hp;
} Monster;

// Инициализация игры
void init_game(Player *player, Monster *monsters, int monster_count);

// Обработка ввода игрока
void process_input(Player *player);

#endif  // GAME_H
