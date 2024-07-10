#ifndef COMBAT_H
#define COMBAT_H

#include "game.h"
#include "map.h"
#include <stdio.h>

// Система сражений
void combat(Player *player, Monster *monster);
int check_monster(int x, int y, int i, int j);

#endif  // COMBAT_H
