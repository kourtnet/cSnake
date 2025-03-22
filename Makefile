CC = gcc
#CFLAGS = -Werror -Wall -Wextra -std=c11 -lncurses
CFLAGS = -Wall -Wextra -std=c11 -lncurses

TARGET = csnake

.PHONY: all clean install

all: $(TARGET)

$(TARGET): build/main.o build/renderer.o build/gameField.o
	$(CC) $(CFLAGS) build/main.o build/renderer.o build/gameField.o -o $(TARGET) 

build/main.o: src/main.c src/renderer.c src/gameField.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/renderer.o: src/renderer.c
	$(CC) $(CFLAGS) -c src/renderer.c -o build/renderer.o 

build/gameField.o: src/gameField.c
	$(CC) $(CFLAGS) -c src/gameField.c -o build/gameField.o 

clean:
	rm -rf build/* 

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
