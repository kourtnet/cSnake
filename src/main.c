#include "renderer.h"

#define WALL_SYMBOL '#'

int main() {
  
  int rowsNumber, columnsNumber;
  initTerminal(&rowsNumber, &columnsNumber);

  render_walls(rowsNumber, columnsNumber, WALL_SYMBOL);
  getch();
  endwin();
  
  return 0;
}
