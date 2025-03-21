#ifndef RENDERER_H
#define RENDERER_H

#include <ncurses.h>

void initTerminal(int *rowsNumber, int *columnsNumber);
void render_walls(int rowsNumber, int columnsNumber, char wallSymbol);

#endif
