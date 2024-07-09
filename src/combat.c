#include "../include/combat.h"

#include <stdio.h>

void combat(Player *player, Monster *monster) {
    printf("A battle begins!\n");
    while (monster->hp > 0 && player->hp > 0) {
        monster->hp -= player->attack;
        printf("You hit the monster! Monster HP: %d\n", monster->hp);
        if (monster->hp > 0) {
            player->hp -= 1;  // Монстр наносит ответный удар
            printf("Monster hits you! Your HP: %d\n", player->hp);
        }
    }

    if (player->hp > 0) {
        printf("You defeated the monster!\n");
    } else {
        printf("You were defeated by the monster...\n");
    }
}
