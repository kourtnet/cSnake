#include "renderer.h"
#include "coordsPoint.h"
#include "gameField.h"

int main() {
  int rowsNumber, columnsNumber;
  init_terminal(&rowsNumber, &columnsNumber);
  int fieldHeight = rowsNumber - 2;
  int fieldWidth= columnsNumber - 2;
  CoordsPoint appleCoords, snakeTailCoords, snakeHeadCoords;
  int *fieldArrayBegining = 0;
  int direction = 2;
  if (init_game_field(fieldHeight, fieldWidth, &fieldArrayBegining, &appleCoords, 
                  &snakeHeadCoords, &snakeTailCoords, direction)) {

    render_first_frame(rowsNumber, columnsNumber, appleCoords, snakeTailCoords);
    getch();
    free(fieldArrayBegining);
  }
  endwin();
  
  return 0;
}
