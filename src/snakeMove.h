#ifndef SNAKE_MOVE_H
#define SNAKE_MOVE_H

#include "coordsPoint.h"

_Bool snakeMove(int fieldHeight, int fieldWidth, int **arrayBegin, CoordsPoint snakeHeadCoords,
    CoordsPoint snakeTailCoords);
#endif
