#include "renderer.h"
#include "coordsPoint.h"
#include "gameField.h"
//#include "gameField.h"

int main() {
  int rowsNumber, columnsNumber;
  init_terminal(&rowsNumber, &columnsNumber);

  CoordsPoint appleCoords, snakeTailCoords, snakeHeadCoords;
  int *fieldArrayBegining = 0;
  int direction = 2;
  if (init_game_field(rowsNumber, columnsNumber, &fieldArrayBegining, &appleCoords, 
                  &snakeHeadCoords, &snakeTailCoords, direction)) {

    render_first_frame(rowsNumber, columnsNumber, appleCoords, snakeTailCoords);
    getch();
    free(fieldArrayBegining);
  }
  endwin();
  
  return 0;
}
