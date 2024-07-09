#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEMS 10
#include "game.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int effect;  // Например, увеличение HP или атаки
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Inventory;

// Инициализация инвентаря
void init_inventory(Inventory *inventory);

// Добавление предмета в инвентарь
void add_item(Inventory *inventory, Item item);

// Использование предмета
void use_item(Inventory *inventory, int item_index, Player *player);

#endif  // INVENTORY_H
