#include "chess_board.h"

int main() {
    int x, y;
    piece p;

    x = START_OF_THE_BOARD_X;
    y = START_OF_THE_BOARD_Y;
    
    hideCursor();
    system("cls");
    drawBoard(x, y);
    accommodatePieces(x, y, p);
    while (1) {

    }

    return 0;
}