#include <stdio.h>
#include <stdlib.h>

#include "../include/combat.h"
#include "../include/game.h"
#include "../include/inventory.h"
#include "../include/map.h"

int main() {
    Player player;
    int monster_count = 15;
    Monster monsters[monster_count];
    Inventory inventory;

    init_game(&player, monsters, monster_count);
    init_inventory(&inventory);

    // Добавление примера предмета в инвентарь
    Item potion = {1, "Health Potion", 5};
    add_item(&inventory, potion);

    while (player.hp > 0) {
        draw_map(&player, monsters, monster_count);
        process_input(&player);

        // Проверка столкновений с монстрами
        for (int i = 0; i < monster_count; i++) {
            if (!check_monster(monsters[i].x, monsters[i].y, player.x, player.y)) {
                combat(&player, &monsters[i]);
                if (monsters[i].hp <= 0) {
                    monsters[i].x = -1;  // Убираем монстра с карты
                    monsters[i].y = -1;
                } else if (player.x == 40, player.y == 10) {
                    printf("You passed the level!")ж
                    return 0;
                } else {
                    printf("Game Over!\n");
                    return 0;
                    }
            }
        }

        
    }

    printf("Game Over!\n");
    return 0;
}
