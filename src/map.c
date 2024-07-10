#include "../include/map.h"

// Лабиринт: '#' - стена, ' ' - проход
const char lab_map[MAP_HEIGHT][MAP_WIDTH + 1];

// Функция для загрузки карты из файла
void load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < MAP_HEIGHT; y++) {
        if (fgets(lab_map[y], MAP_WIDTH + 2, file) == NULL) {
            perror("Failed to read map file");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void draw_map(Player *player, Monster monsters[], int monster_count) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (player->x == x && player->y == y) {
                printf("@");  // Игрок
            } else {
                int is_monster = 0;
                for (int i = 0; i < monster_count; i++) {
                    if (monsters[i].x == x && monsters[i].y == y) {
                        printf("M");  // Монстр
                        is_monster = 1;
                        break;
                    }
                }
                if (!is_monster) {
                    printf("%c", lab_map[y][x]);
                }
            }
        }
        printf("\n");
    }
}

// Функция для отображения карты
// void draw_map(Player *player, Monster monsters[], int monster_count) {
//     for (int y = 0; y < MAP_HEIGHT; y++) {
//         for (int x = 0; x < MAP_WIDTH; x++) {
//             if (player->x == x && player->y == y) {
//                 printf("@");  // Игрок
//             } else {
//                 int is_monster = 0;
//                 for (int i = 0; i < monster_count; i++) {
//                     if (monsters[i].x == x && monsters[i].y == y) {
//                         printf("M");  // Монстр
//                         is_monster = 1;
//                         break;
//                     }
//                 }
//                 if (!is_monster) {
//                     printf("%c", lab_map[y][x]);
//                 }
//             }
//         }
//         printf("\n");
//     }
// }

// Функция для проверки возможности перемещения
int can_move(int x, int y) {
    if (x < 0 && x >= MAP_WIDTH && y < 0 && y >= MAP_HEIGHT && lab_map[y][x] != '#' && lab_map[y][x] != '|') {
        return 0;
    } 
    return 1;
}
