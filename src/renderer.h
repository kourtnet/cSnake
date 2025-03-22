#ifndef RENDERER_H
#define RENDERER_H

#include "coordsPoint.h"

#include <ncurses.h>

#define WALL_SYMBOL '#'
#define APPLE_SYMBOL '@'
#define SNAKE_SYMBOL 'o'

void init_terminal(int *rowsNumber, int *columnsNumber);
void render_walls(int rowsNumber, int columnsNumber);
void render_apple(CoordsPoint coords);
void render_start_snake(CoordsPoint coords);
void render_primitive(CoordsPoint coords, char symbol);
#endif
