#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#define MINIMAL_ROWS_NUMBER 3
#define MINIMAL_COLUMNS_NUMBER 6
#define FIELD_SIZE_SUBTRACT 2
#define SNAKE_START_X_COORD
#include <stdlib.h>

_Bool init_game_field(int rowsNumber, int columnsNumber, int *arrayBegining, CoordsPoint *appleCoords,
    CoordsPoint *snakeHeadCoords, CoordsPoint *snakeTailCoords);

#endif
