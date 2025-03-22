#include "gameField.h"
#include <ncurses.h>
_Bool init_game_field(int fieldHeight, int fieldWidth, int **arrayBegining, CoordsPoint *appleCoords, 
                     CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  if(fieldHeight < MINIMAL_ROW_NUMBER || fieldWidth < MINIMAL_COLUMN_NUMBER) {
    return 0;
  }
  init_field_array(fieldHeight, fieldWidth, arrayBegining);
  init_snake_coords(fieldHeight, fieldWidth, arrayBegining, snakeHeadCoords, snakeTailCoords, direction);
  init_apple_coords(fieldHeight, fieldWidth, arrayBegining, appleCoords);
  return 1;
}
void init_field_array(int fieldHeight, int fieldWidth, int **arrayBegining) {
  *arrayBegining = (int*)malloc (fieldHeight * fieldWidth * sizeof(int));

  for(int i = 0; i < fieldHeight; ++i) {
    for (int j = 0; j < fieldWidth; ++j) {
      (*arrayBegining)[i * fieldWidth+ j] = 0;
    }
  }
}
void init_snake_coords(int fieldHeight, int fieldWidth, int **arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction) {
  snakeTailCoords->x = 0;
  snakeTailCoords->y = (fieldHeight / 2 - 1 != -1 ? fieldHeight / 2 - 1 : 0);
  snakeHeadCoords->x = 2;
  snakeHeadCoords->y = snakeTailCoords->y;
  (*arrayBegining)[snakeTailCoords->y * fieldWidth + snakeTailCoords->x] = direction;
  (*arrayBegining)[snakeTailCoords->y * fieldWidth + snakeTailCoords->x + 1] = direction;
  (*arrayBegining)[snakeHeadCoords->y * fieldWidth + snakeHeadCoords->x] = direction;
}

void init_apple_coords(int fieldHeight, int fieldWidth, int **arrayBegining, CoordsPoint* appleCoords) {
  srand(time(NULL));
  do {
    appleCoords->x = rand() % fieldWidth;
    appleCoords->y = rand() % fieldHeight;
  } while((*arrayBegining)[appleCoords->y * fieldWidth + appleCoords->x] != 0);
  (*arrayBegining)[appleCoords->y * fieldWidth + appleCoords->x] = 1;
}
