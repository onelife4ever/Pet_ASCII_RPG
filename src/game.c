#include "../include/game.h"
#include "../include/combat.h"
#include "../include/map.h"

void init_game(Player *player, Monster *monsters, int monster_count) {
    player->x = 0;
    player->y = 110;
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
        if(!can_move(player->x, player->y)){
            player->y--;
            break;
        } else {break;}
        case 's':
        if(!can_move(player->x, player->y)){
            player->y++;
            break;
        } else {break;}
        case 'a':
        if(!can_move(player->x, player->y)){
            player->x--;
            break;
        } else {break;}
        case 'd':
        if(!can_move(player->x, player->y)){
            player->x++;
            break;
        } else {break;}
        // case 'i':
        // use_item(&inventory, 0, &player);  // Используем первый предмет в инвентаре
    }
}
