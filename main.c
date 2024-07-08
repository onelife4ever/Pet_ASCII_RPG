#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "combat.h"
#include "inventory.h"

int main() {
    Player player;
    int monster_count = 5;
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
            if (player.x == monsters[i].x && player.y == monsters[i].y) {
                combat(&player, &monsters[i]);
                if (monsters[i].hp <= 0) {
                    monsters[i].x = -1; // Убираем монстра с карты
                    monsters[i].y = -1;
                }
            }
        }

        // Пример использования предмета из инвентаря
        use_item(&inventory, 0, &player); // Используем первый предмет в инвентаре
    }

    printf("Game Over!\n");
    return 0;
}
