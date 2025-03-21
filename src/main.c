#include "renderer.h"

#define WALL_SYMBOL '#'

int main() {
  
  int rowsNumber, columnsNumber;
  init_terminal(&rowsNumber, &columnsNumber);
  render_walls(rowsNumber, columnsNumber, WALL_SYMBOL);
  getch();
  endwin();
  
  return 0;
}
