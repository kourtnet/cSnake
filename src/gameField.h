#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#define MINIMAL_ROWS_NUMBER 3
#define MINIMAL_COLUMNS_NUMBER 6
#define FIELD_SIZE_SUBTRACT 2

#include <stdlib.h>
#include <time.h>

#include "coordsPoint.h"

_Bool init_game_field(int rowsNumber, int columnsNumber, int *arrayBegining, CoordsPoint *appleCoords,
    CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords);

void init_field_array(int rowsNumber, int columnsNumber, int *arrayBegining);

void init_snake_coords(int columnsNumber, int *arrayBegining, CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords);

#endif
