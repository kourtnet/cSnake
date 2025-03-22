#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#define MINIMAL_ROW_NUMBER 1
#define MINIMAL_COLUMN_NUMBER 3

#include <stdlib.h>
#include <time.h>

#include "coordsPoint.h"

_Bool init_game_field(int fieldHeight, int fieldWidth, int **arrayBegining, CoordsPoint *appleCoords,
    CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction);
void init_field_array(int fieldHeight, int fieldWidth, int **arrayBegining);
void init_snake_coords(int fieldHeight, int fieldWidth, int **arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction);
void init_apple_coords(int fieldHeight, int fieldWidth, int  **arrayBegining, CoordsPoint* appleCoords); 
#endif
