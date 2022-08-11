#include "player.h"

int main() {
    int x, y, key;
    piece p;
    player p1, p2;

    x = START_OF_THE_BOARD_X;
    y = START_OF_THE_BOARD_Y;
    
    hideCursor();
    system("cls");
    drawBoard(x, y);
    accommodatePieces(x, y, p);
    p1 = createPlayer(p1);
    p1 = playerMovement(p1.x, p1.y, p1);
    while (1) {

    }

    return 0;
}