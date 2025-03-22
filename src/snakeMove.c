#include "snakeMove.h"

_Bool snake_move(int fieldHeight, int fieldWidth, int **arrayBegin, CoordsPoint snakeHeadCoords,
    CoordsPoint snakeTailCoords) {
  int xOffset = 0, yOffset = 0;
  set_offsets(arrayBegin, snakeHeadCoords, fieldWidth, &xOffset, &yOffset);
  if(snakeHeadCoords.x + xOffset < 0 || snakeHeadCoords.x + xOffset >= fieldWidth || snakeHeadCoords.y + yOffset < 0 || 
  snakeHeadCoords.y + yOffset >= fieldHeight) {
    return 0;
  }
  int nextTileValue = (*arrayBegin)[(snakeHeadCoords.y + yOffset) * fieldWidth + snakeHeadCoords.x + xOffset];
  if(nextTileValue >= 2 && nextTileValue <= 5) {
    return 0;
  } 
  if(nextTileValue == 1) {
    move_snake_body_part(arrayBegin, &snakeHeadCoords, fieldWidth, 0);
  } else {
    move_snake_body_part(arrayBegin, &snakeHeadCoords, fieldWidth, 0);
    move_snake_body_part(arrayBegin, &snakeTailCoords, fieldWidth, 1);
  } 
  return 1;
}

void set_offsets(int **arrayBegin, CoordsPoint coords, int fieldWidth, int *xOffset, int *yOffset) {
  switch((*arrayBegin)[coords.y * fieldWidth + coords.x]) {
    case 2:
      *xOffset= 1;
      break;
    case 3:
      *yOffset = -1;
      break;
    case 4:
      *xOffset = -1;
      break;
    case 5:
      *yOffset = 1;
      break;
  }
}

void move_snake_body_part(int **arrayBegin, CoordsPoint *coords, int fieldWidth, _Bool isTail) {
  int oldValue = (*arrayBegin)[coords->y * fieldWidth + coords->x];
  int xOffset = 0, yOffset = 0;

  set_offsets(arrayBegin, coords, fieldWidth, &xOffset, &yOffset);
  if(isTail) {
    (*arrayBegin)[coords->y * fieldWidth + coords->x] = 0; 
  }
  coords->x += xOffset;
  coords->y += yOffset;
}
