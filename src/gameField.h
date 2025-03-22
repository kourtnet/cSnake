#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#define MINIMAL_ROW_NUMBER 3
#define MINIMAL_COLUMN_NUMBER 6
#define FIELD_SIZE_SUBTRACT 2

#include <stdlib.h>
#include <time.h>

#include "coordsPoint.h"

_Bool init_game_field(int rowsNumber, int columnsNumber, int **arrayBegining, CoordsPoint *appleCoords,
    CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction);
void init_field_array(int rowsNumber, int columnsNumber, int **arrayBegining);
void init_snake_coords(int rowsNumber, int columnsNumber, int **arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords, int direction);
void init_apple_coords(int rowsNumber, int columnsNumber, int  **arrayBegining, CoordsPoint* appleCoords); 
#endif
