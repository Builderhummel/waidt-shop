CFLAGS = -Wall -g
CC = gcc -std=c99 
OBJ_PATH = obj
VPATH = src

all: main

main: main.o
	$(CC) $(CFLAGS) $(OBJ_PATH)/main.o -o main

main.o: main.c
	$(CC) $(CFLAGS) src/main.c -c -o $(OBJ_PATH)/main.o

clean:
	rm -rf main
	rm -rf $(OBJ_PATH)/*.o
