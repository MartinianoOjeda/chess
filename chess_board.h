#include "chess.h"

#define SQUARE_X 4
#define SQUARE 10
#define DARK_SQUARE 30
#define LIGHT_SQUARE 37
#define CHAR 219
#define BOARD 64

#define X 6
#define Y (X/2)
#define DRAW_SQUARE (X*Y)


typedef int draw[DRAW_SQUARE];

void drawSquare(int x, int y, int color) {
    int i, x2;
    x2 = x;
    for(i = 0; i < DRAW_SQUARE; i++) {
        if(x == x2+X) {
            y += 1;
            x = x2;
        }
        print(x, y, color, CHAR);
        x += 1;
    }
}

void drawBoard(int x, int y) {
    int i, x2, color1, color2, color3;
    x2 = x;
    color1 = DARK_SQUARE;
    color2 = LIGHT_SQUARE;

    while(y < (Y*8)) {
        for(i = 0; i < SQUARE_X; i++) {
            drawSquare(x, y, color1);
            x +=X;
            drawSquare(x, y, color2);
            x +=X;
        }
        x = x2;
        y += Y;
        color3 = color1;
        color1 = color2;
        color2 = color3;
    }
}