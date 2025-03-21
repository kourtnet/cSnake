CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c11 -lncurses

TARGET = csnake

.PHONY: all clean install

all: $(TARGET)

$(TARGET): build/main.o build/renderer.o
	$(CC) $(CFLAGS) build/main.o build/renderer.o -o $(TARGET) 

build/main.o: src/main.c src/renderer.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o 

build/renderer.o: src/renderer.c
	$(CC) $(CFLAGS) -c src/renderer.c -o build/renderer.o 

clean:
	rm -rf build/* 

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
