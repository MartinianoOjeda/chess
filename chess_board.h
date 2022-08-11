#include "chess_pieces.h"

#define SQUARE_X 4
#define DARK_SQUARE 33
#define LIGHT_SQUARE 30
#define CHAR 219

typedef int draw[DRAW_SQUARE];

void drawSquare(int x, int y, int tone, int color) {
    int i, x2;
    x2 = x;
    for(i = 0; i < DRAW_SQUARE; i++) {
        if(x == x2+X) {
            y += 1;
            x = x2;
        }
        printXY(x, y, color, tone, CHAR);
        x += 1;
    }
}

void drawBoard(int x, int y) {
    int i, x2, color1, color2, color3, tone1, tone2, tone3;
    x2 = x;
    color1 = LIGHT_SQUARE;
    color2 = DARK_SQUARE;
    tone1 = 1;
    tone2 = 0;

    while(y < (Y*8)) {
        for(i = 0; i < SQUARE_X; i++) {
            drawSquare(x, y, tone1, color1);
            x +=X;
            drawSquare(x, y, tone2, color2);
            x +=X;
        }
        x = x2;
        y += Y;
        color3 = color1;
        color1 = color2;
        color2 = color3;
        tone3 = tone1;
        tone1 = tone2;
        tone2 = tone3;
    }
}