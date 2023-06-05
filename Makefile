CFLAGS = -Wall -g
CC = gcc #-std=c99 
OBJ_PATH = obj
VPATH = src src/backend/item

all: main

main: item_object.o main.o
	$(CC) $(CFLAGS) $(OBJ_PATH)/main.o $(OBJ_PATH)/item_object.o -Isrc/backend/item/ -o main

main.o: main.c
	$(CC) $(CFLAGS) src/main.c -c -o $(OBJ_PATH)/main.o

# backend
# item
item_object.o: item_object.c
	$(CC) $(CFLAGS) src/backend/item/item_object.c -c -o $(OBJ_PATH)/item_object.o


clean:
	rm -rf main
	rm -rf $(OBJ_PATH)/*.o
