#include "chess_board.h"

#define POINT 219
#define COLOR_POINT 31


typedef struct pla{
    int x, y, previuos_x, previuos_y;
}player;

player createPlayer(player p) {
    p.x = ((X*8)/2)-2;
    p.y = (Y*8)/2;
    p.previuos_x = p.x;
    p.previuos_y = p.y;
    return p;
}

player playerMovement(int x, int y, player p) {
    printXY(p.previuos_x, p.previuos_y, BLACK, 0, POINT);
    printXY(p.previuos_x+1, p.previuos_y, BLACK, 0, POINT);
    printXY(x, y, COLOR_POINT, 1, POINT);
    printXY(x+1, y, COLOR_POINT, 1, POINT);
    p.x = x;
    p.y = y;
}

