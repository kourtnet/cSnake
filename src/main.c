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
  //DELETE LATER
  appleCoords.x = 0;
  appleCoords.y = 0;
  snakeTailCoords.y = 3;
  snakeTailCoords.x = 2;
  /*arrayBegining = (int*)malloc ((rowsNumber - 2) * (columnsNumber - 2) * sizeof(int));
  arrayBegining[3 * columnsNumber + 2] = 2;
  arrayBegining[3 * columnsNumber + 3] = 2;
  arrayBegining[3 * columnsNumber + 4] = 2;
  arrayBegining[0] = 1;
  for(int i = 0; i < rowsNumber; ++i) {
    for (int j = 0; j < columnsNumber; ++j) {
      arrayBegining[i * rowsNumber + j] = 0;
    }
  }*/
  //DELETE LATER
  render_walls(rowsNumber, columnsNumber);
  render_apple(appleCoords);
  render_start_snake(snakeTailCoords);
  getch();
  endwin();
  
  return 0;
}
