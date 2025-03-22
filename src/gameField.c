#include "gameField.h"
#include <ncurses.h>
_Bool init_game_field(int rowsNumber, int columnsNumber, int **arrayBegining, CoordsPoint *appleCoords, 
                     CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  if(rowsNumber < MINIMAL_ROW_NUMBER || columnsNumber < MINIMAL_COLUMN_NUMBER) {
    return 0;
  }
  init_field_array(rowsNumber, columnsNumber, arrayBegining);
  init_snake_coords(rowsNumber, columnsNumber, arrayBegining, snakeHeadCoords, snakeTailCoords, direction);
  init_apple_coords(rowsNumber, columnsNumber, arrayBegining, appleCoords);
  return 1;
}
void init_field_array(int rowsNumber, int columnsNumber, int **arrayBegining) {
  *arrayBegining = (int*)malloc ((rowsNumber - FIELD_SIZE_SUBTRACT) * (columnsNumber - FIELD_SIZE_SUBTRACT) * sizeof(int));

  for(int i = 0; i < rowsNumber - FIELD_SIZE_SUBTRACT; ++i) {
    for (int j = 0; j < columnsNumber - FIELD_SIZE_SUBTRACT; ++j) {
      (*arrayBegining)[i * (columnsNumber - FIELD_SIZE_SUBTRACT)+ j] = 0;
    }
  }
}
void init_snake_coords(int rowsNumber, int columnsNumber, int **arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  snakeTailCoords->x = 0;
  snakeTailCoords->y = ((rowsNumber- FIELD_SIZE_SUBTRACT) / 2 - 1 != -1 ? (rowsNumber - FIELD_SIZE_SUBTRACT) / 2 - 1 : 0);
  snakeHeadCoords->x = 0 + 2;
  snakeHeadCoords->y = snakeTailCoords->y;
  (*arrayBegining)[snakeTailCoords->y * (columnsNumber - FIELD_SIZE_SUBTRACT) + snakeTailCoords->x] = direction;
  (*arrayBegining)[snakeTailCoords->y * (columnsNumber - FIELD_SIZE_SUBTRACT) + snakeTailCoords->x + 1] = direction;
  (*arrayBegining)[snakeHeadCoords->y * (columnsNumber - FIELD_SIZE_SUBTRACT) + snakeHeadCoords->x] = direction;
}

void init_apple_coords(int rowsNumber, int columnsNumber, int **arrayBegining, CoordsPoint* appleCoords) {
  srand(time(NULL));
  do {
    appleCoords->x = rand() % (columnsNumber - FIELD_SIZE_SUBTRACT);
    appleCoords->y = rand() % (rowsNumber - FIELD_SIZE_SUBTRACT);
  } while((*arrayBegining)[appleCoords->y * (columnsNumber - FIELD_SIZE_SUBTRACT) + appleCoords->x] != 0);
  (*arrayBegining)[appleCoords->y * (columnsNumber - FIELD_SIZE_SUBTRACT) + appleCoords->x] = 1;
}
