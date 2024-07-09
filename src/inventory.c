#include "../include/inventory.h"
#include <stdio.h>
#include <string.h>

void init_inventory(Inventory *inventory) {
    inventory->item_count = 0;
}

void add_item(Inventory *inventory, Item item) {
    if (inventory->item_count < MAX_ITEMS) {
        inventory->items[inventory->item_count] = item;
        inventory->item_count++;
        printf("Added %s to inventory.\n", item.name);
    } else {
        printf("Inventory is full!\n");
    }
}

void use_item(Inventory *inventory, int item_index, Player *player) {
    if (item_index >= 0 && item_index < inventory->item_count) {
        Item item = inventory->items[item_index];
        // Пример использования предмета: увеличение HP игрока
        player->hp += item.effect;
        printf("Used %s. Player HP: %d\n", item.name, player->hp);

        // Удаление использованного предмета из инвентаря
        for (int i = item_index; i < inventory->item_count - 1; i++) {
            inventory->items[i] = inventory->items[i + 1];
        }
        inventory->item_count--;
    } else {
        printf("Invalid item index!\n");
    }
}
