CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./include
SRC = main.c game.c map.c combat.c inventory.c
OBJ = $(SRC:.c=.o)
EXEC = rpg_game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
