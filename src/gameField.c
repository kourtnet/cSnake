#include "gameField.h"

_Bool init_game_field(int rowsNumber, int columnsNumber, int *arrayBegining, CoordsPoint *appleCoords, 
                     CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  if(rowsNumber < MINIMAL_ROW_NUMBER || columnsNumber < MINIMAL_COLUMN_NUMBER) {
    return 0;
  }
  init_field_array(rowsNumber, columnsNumber, arrayBegining);
  init_snake_coords(columnsNumber, arrayBegining, snakeHeadCoords, snakeTailCoords, direction);
  init_apple_coords(rowsNumber, columnsNumber, arrayBegining, appleCoords);
  return 1;
}
void init_field_array(int rowsNumber, int columnsNumber, int *arrayBegining) {
  arrayBegining = (int*)malloc ((rowsNumber - FIELD_SIZE_SUBTRACT) * (columnsNumber - FIELD_SIZE_SUBTRACT) * sizeof(int));

  for(int i = 0; i < rowsNumber; ++i) {
    for (int j = 0; j < columnsNumber; ++j) {
      arrayBegining[i * rowsNumber + j] = 0;
    }
  }
}
void init_snake_coords(int columnsNumber, int *arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  snakeTailCoords->x = SNAKE_START_X_COORD;
  snakeTailCoords->y = (columnsNumber / 2 - 1 != -1 ? columnsNumber / 2 - 1 : 0);
  snakeHeadCoords->x = SNAKE_START_X_COORD + 2;
  snakeHeadCoords->y = snakeTailCoords->y;

  arrayBegining[snakeTailCoords->y * rowsNumber + snakeTailCoords->x] = direction;
  arrayBegining[snakeTailCoords->y * rowsNumber + snakeTailCoords->x + 1] = direction;
  arrayBegining[snakeHeadCoords->y * rowsNumber + snakeHeadCoords->x] = direction;
}

void init_apple_coords(int rowsNumber, int columnsNumber, int* arrayBegining, CoordsPoint* appleCoords) {
  srand(time(NULL));
  do {
    appleCoords->x = rand() % columnsNumber;
    appleCoords->y = rand() % rowsNumber;
  } while(arrayBegining[appleCoords->y * columnsNumber + appleCoords->x] != 0);
  arrayBegining[appleCoords->y *columnsNumber + appleCoords->x] = 1;
}
