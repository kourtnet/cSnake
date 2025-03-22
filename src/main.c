#include "renderer.h"
#include "coordsPoint.h"
//#include "gameField.h"

int main() {
  
  int rowsNumber, columnsNumber;
  init_terminal(&rowsNumber, &columnsNumber);

  CoordsPoint appleCoords, snakeTailCoords/*, snakeHeadCoords*/;
  //int *fieldArrayBegining;
  //int direction = 2;
  //init_game_field(rowsNumber, columnsNumber, fieldArrayBegining, &appleCoords, 
  //                &snakeHeadCoords, &snakeTailCoords, direction);
  render_first_frame(rowsNumber, columnsNumber, appleCoords, snakeTailCoords);
  getch();
  endwin();
  
  return 0;
}
