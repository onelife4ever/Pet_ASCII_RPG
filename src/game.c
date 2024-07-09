#include "../include/game.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/combat.h"
#include "../include/map.h"

void init_game(Player *player, Monster *monsters, int monster_count) {
    player->x = MAP_WIDTH / 2;
    player->y = MAP_HEIGHT / 2;
    player->hp = 10;
    player->attack = 2;

    // Инициализация монстров
    for (int i = 0; i < monster_count; i++) {
        monsters[i].x = rand() % MAP_WIDTH;
        monsters[i].y = rand() % MAP_HEIGHT;
        monsters[i].hp = 5;
    }
}

void process_input(Player *player) {
    char input = getchar();
    switch (input) {
        case 'w':
            player->y--;
            break;
        case 's':
            player->y++;
            break;
        case 'a':
            player->x--;
            break;
        case 'd':
            player->x++;
            break;
    }
}
