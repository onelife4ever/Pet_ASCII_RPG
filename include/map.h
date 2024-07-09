#ifndef MAP_H
#define MAP_H

#include "game.h"

// Размеры карты
#define MAP_WIDTH 120
#define MAP_HEIGHT 40

// Функция для отображения карты
void draw_map(Player *player, Monster monsters[], int monster_count);

// Функция для проверки возможности перемещения
int can_move(int x, int y);

#endif // MAP_H
