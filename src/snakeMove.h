#ifndef SNAKE_MOVE_H
#define SNAKE_MOVE_H

#include "coordsPoint.h"

_Bool snake_move(int fieldHeight, int fieldWidth, int **arrayBegin, CoordsPoint snakeHeadCoords,
    CoordsPoint snakeTailCoords);
void set_offsets(int **arrayBegin, CoordsPoint coords, int fieldWidth, int *xOffset, int *yOffset); 
void move_snake_body_part(int **arrayBegin, CoordsPoint *coords, int fieldWidth, _Bool isTail);

#endif
