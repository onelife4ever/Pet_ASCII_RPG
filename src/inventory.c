#include "../include/inventory.h"

void init_inventory(Inventory *inventory) { inventory->item_count = 0; }

void add_item(Inventory *inventory, Item item) {
    if (inventory->item_count < MAX_ITEMS) {
        inventory->items[inventory->item_count] = item;
        inventory->item_count++;
        printf("Added %s to inventory.\n", item.name);
    } else {
        printf("Inventory is full!\n");
    }
}

// void select_item(){
//     printf("You have next items:\n")
//             for (int i = 0; i <= 10; i++){
//                 printf("%d. %c, effect: %d.", Item.id[i], Item.name[i], Item.effect[i]);
//             }
//                 switch (expression)
//             {
//             case /* constant-expression */:
//                 /* code */
//                 break;
            
//             default:
//                 break;
//             }
        // use_item(&inventory, 0, &player);  // Используем первый предмет в инвентаре
// }

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
