CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: rpg_game

rpg_game: main.o game.o map.o combat.o inventory.o
	$(CC) $(CFLAGS) -o rpg_game main.o game.o map.o combat.o inventory.o

main.o: main.c game.h map.h combat.h inventory.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h map.h combat.h
	$(CC) $(CFLAGS) -c game.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

combat.o: combat.c combat.h
	$(CC) $(CFLAGS) -c combat.c

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c inventory.c

clean:
	rm -f rpg_game *.o
