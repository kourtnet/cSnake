#include "renderer.h"

void init_terminal(int *rowsNumber, int *columnsNumber){
  initscr();
  getmaxyx(stdscr, *rowsNumber, *columnsNumber);
}
void render_walls(int rowsNumber, int columnsNumber, char wallSymbol) {
  for(int i = 0; i < columnsNumber; ++i) {
    mvprintw(0, i, "%c", wallSymbol);
    mvprintw(rowsNumber - 1, i, "%c", wallSymbol);
  }
  for(int i = 1; i < rowsNumber - 1; ++i) {
    mvprintw(i, 0, "%c", wallSymbol);
    mvprintw(i, columnsNumber - 1, "%c", wallSymbol);
  }
}
