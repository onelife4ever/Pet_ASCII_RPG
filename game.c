#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "combat.h"

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

void draw_map(Player *player, Monster *monsters, int monster_count) {
    char map[MAP_HEIGHT][MAP_WIDTH];

    // Очистка карты
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '.';
        }
    }

    // Размещение игрока
    map[player->y][player->x] = '@';

    // Размещение монстров
    for (int i = 0; i < monster_count; i++) {
        map[monsters[i].y][monsters[i].x] = 'M';
    }

    // Отрисовка карты
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

void process_input(Player *player) {
    char input = getchar();
    switch (input) {
        case 'w': player->y--; break;
        case 's': player->y++; break;
        case 'a': player->x--; break;
        case 'd': player->x++; break;
    }
}

void combat(Player *player, Monster *monster) {
    monster->hp -= player->attack;
    if (monster->hp > 0) {
        player->hp -= 1; // Монстр наносит ответный удар
    }
}
