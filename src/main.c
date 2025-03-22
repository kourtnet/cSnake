#include "renderer.h"
#include "coordsPoint.h"
#include "gameField.h"
#define WALL_SYMBOL '#'

int main() {
  
  int rowsNumber, columnsNumber;
  init_terminal(&rowsNumber, &columnsNumber);

  CoordsPoint appleCoords, snakeTailCoords, snakeHeadCoords;
  int *fieldArrayBegining;
  init_game_field(rowsNumber, columnsNumber, fieldArrayBegining, &appleCoords, &snakeHeadCoords, &snakeTailCoords);

  render_walls(rowsNumber, columnsNumber, WALL_SYMBOL);
  getch();
  endwin();
  
  return 0;
}
