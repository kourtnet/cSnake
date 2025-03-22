#include "renderer.h"

void init_terminal(int *rowsNumber, int *columnsNumber){
  initscr();
  getmaxyx(stdscr, *rowsNumber, *columnsNumber);
}
void render_walls(int rowsNumber, int columnsNumber) {
  for(int i = 0; i < columnsNumber; ++i) {
    mvprintw(0, i, "%c", WALL_SYMBOL);
    mvprintw(rowsNumber - 1, i, "%c", WALL_SYMBOL);
  }
  for(int i = 1; i < rowsNumber - 1; ++i) {
    mvprintw(i, 0, "%c", WALL_SYMBOL);
    mvprintw(i, columnsNumber - 1, "%c", WALL_SYMBOL);
  }
}

void render_apple(CoordsPoint coords) {
  render_primitive(coords, APPLE_SYMBOL);
}
void render_start_snake(CoordsPoint coords) {
  int oldX = coords.x;
  while(coords.x < oldX + 3) {
    ++coords.x;
    render_primitive(coords, SNAKE_SYMBOL);
  }
}
void render_primitive(CoordsPoint coords, char symbol) {
  mvprintw(coords.y + 1, coords.x + 1, "%c", symbol);
}

void render_first_frame(int rowsNumber, int columnsNumber,
    CoordsPoint appleCoords, CoordsPoint snakeTailCoords) {
  render_walls(rowsNumber, columnsNumber);
  render_apple(appleCoords);
  render_start_snake(snakeTailCoords);
}
