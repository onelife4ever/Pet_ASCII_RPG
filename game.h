#ifndef GAME_H
#define GAME_H

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

typedef struct {
    int x;
    int y;
    int hp;
    int attack;
} Player;

typedef struct {
    int x;
    int y;
    int hp;
} Monster;

// Инициализация игры
void init_game(Player *player, Monster *monsters, int monster_count);

// Отрисовка карты
void draw_map(Player *player, Monster *monsters, int monster_count);

// Обработка ввода игрока
void process_input(Player *player);

// Система сражений
void combat(Player *player, Monster *monster);

#endif // GAME_H
