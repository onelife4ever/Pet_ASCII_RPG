#include "../include/combat.h"

void combat(Player *player, Monster *monster) {
    printf("You are meet the monster. A battle begins!\n");
    while (monster->hp > 0 && player->hp > 0) {
        char input = getchar();
        switch (input) {
            case 'a':
            monster->hp -= player->attack;
            printf("You hit the monster! Monster HP: %d\n", monster->hp);
            if (monster->hp > 0) {
                player->hp -= 1;  // Монстр наносит ответный удар
                printf("Monster hits you! Your HP: %d\n", player->hp);
            }
            break;
            case 'r':
            if(player->hp > 1){
                goto run;  
            }
        }
    }
    
    run: 
    printf("You escaped from the monster.");
    player->x -= 1;
    player->y -= 1;

    if (player->hp > 0 && monster->hp <= 0) {
        printf("You defeated the monster!\n");
    } else {
        printf("You were defeated by the monster...\n");
    }
}


int check_monster(int x, int y, int i, int j) {
    int sum = 0;

    int i_min = i - 1, j_min = j - 1;
    int i_plus = i + 1, j_plus = j + 1;

    if (i_min == x || j_min == y || i_plus == x || i_plus == y) {
        sum = 1;
    }
    
    return sum;
}
