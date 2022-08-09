#include "chess.h"

#define NUMBER_OF_PARTS 12
#define BLACK 30 //color of pieces
#define WHITE 37 //color of piece
#define CHAR 219
#define L_ROOK 1
#define L_KNIGHT 2
#define L_BISHOP 3
#define R_ROOK 4
#define R_KNIGHT 5
#define R_BISHOP 6
#define QUEEN 7
#define KING 8
#define PAWN 9

#define X 6
#define Y (X/2)
#define DRAW_SQUARE (X*Y)

#define START_OF_THE_BOARD_X 2
#define START_OF_THE_BOARD_Y 2

#define BPYP START_OF_THE_BOARD_Y //BLACK PIECES Y POSITION
#define B_PAWN_YP START_OF_THE_BOARD_Y+Y //BLACK PAWN Y POSITION
#define WPYP START_OF_THE_BOARD_Y+(Y*7)//WHITE PICES Y POSITION
#define W_PAWN_YP START_OF_THE_BOARD_Y+(Y*6) //WHITE PAWN Y POSITION

#define LRXP START_OF_THE_BOARD_X //LEFT ROOK X POSITION
#define LKXP START_OF_THE_BOARD_X+X //LEFT KGNIHT X POSITION
#define LBXP START_OF_THE_BOARD_X+(X*2) //LEFT BISHOP X POSITION
#define RRXP START_OF_THE_BOARD_X+(X*7) //RIGHT ROOK X POSITION
#define RKXP START_OF_THE_BOARD_X+(X*6) //RIGHT KGNIHT X POSITION
#define RBXP START_OF_THE_BOARD_X+(X*5) //RIGHT BISHOP X POSITION
#define QXP START_OF_THE_BOARD_X+(X*3) //QUEEN X POSITION
#define KXP START_OF_THE_BOARD_X+(X*4) //KING X POSITION
#define PXP START_OF_THE_BOARD_X //PXP X POSITION

typedef int piece_parts[50];
typedef int parts[NUMBER_OF_PARTS];

typedef struct pieces{
    int x, y, previous_x, previous_y, type, color;
    parts parts;
}piece;

piece rook(piece);
piece kight(piece);
piece bishop(piece);
piece queen(piece);
piece king(piece);
piece pawn(piece);


piece rook(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {1,4,2,3,1,2,3,4,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}
piece knight(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {3,4,2,3,1,2,3,4,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}
piece bishop(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {2,3,2,3,1,2,3,4,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}

piece queen(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {1,4,2,3,2,3,0,0,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}

piece king(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {2,3,1,2,3,4,2,3,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}

piece pawn(piece p) {
    int i;
    int partX[NUMBER_OF_PARTS] =
        {2,3,1,2,3,4,0,0,0,0,0,0};
    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        p.parts[i] = partX[i];
    }
    return p; 
}

piece partsPositions(piece p, int type) {
    p.type = type;
    switch (type) {
        case L_ROOK: p = rook(p);
        break;
        case L_KNIGHT: p = knight(p);
        break;
        case L_BISHOP: p = bishop(p);
        break;
        case R_ROOK: p = rook(p);
        break;
        case R_KNIGHT: p = knight(p);
        break;
        case R_BISHOP: p = bishop(p);
        break;
        case QUEEN: p = queen(p);
        break;
        case KING: p = king(p);
        break;
        case PAWN: p = pawn(p);
    }
    return p;
}

piece piecePositionInBoardY(piece p, int color) {
    p.color = color;
    if(p.color == BLACK) {
        if(p.type == PAWN) {
            p.y = B_PAWN_YP; 
        }
        else{
            p.y = BPYP;
        }
    }
    else {
        if(p.color == WHITE) {
            if(p.type == PAWN) {
                p.y = W_PAWN_YP;
            }
            else {
                p.y = WPYP;
            }
        }
    }
    return p;
}

piece piecePositionInBoardX(piece p) {
    switch (p.type) {
        case L_ROOK: p.x = LRXP;
        break;
        case L_KNIGHT: p.x = LKXP;
        break;
        case L_BISHOP: p.x = LBXP;
        break;
        case R_ROOK: p.x = RRXP;
        break;
        case R_KNIGHT: p.x = RKXP;
        break;
        case R_BISHOP: p.x = RBXP;
        break;
        case QUEEN: p.x = QXP;
        break;
        case KING: p.x = KXP;
        break;
        case PAWN: p.x = PXP;
    }
    return p;
}

piece createPiece(int x, int y, piece p, int type, int color) {
    int i, n, x2;
    p = partsPositions(p, type);
    p = piecePositionInBoardY(p, color);
    p = piecePositionInBoardX(p);
    p.previous_x = p.x;
    p.previous_y = p.y;
    n = 0;
    x2 = x;
    y  = p.y;
    if(p.type == PAWN) {
        y = y + 1;
        p.x = x2;
    }

    for(i = 0; i < NUMBER_OF_PARTS; i++) {
        
        if(p.parts[i] == 0) {
            break;
        }
        x = p.x + p.parts[i];

        if(p.parts[i] < n) {
            y += 1;
        }
        n = p.parts[i];
        if(p.color == BLACK) {
            printXY(x, y, color, 0, CHAR);
        }
        else {
            printXY(x, y, color, 1, CHAR);
        }
    }
    return p;
}

void accommodatePieces(int x, int y, piece p) {
    int i, xp;
    x = xp;
    p = createPiece(x, y, p, L_ROOK, BLACK);
    p = createPiece(x, y, p, L_KNIGHT, BLACK);
    p = createPiece(x, y, p, L_BISHOP, BLACK);
    p = createPiece(x, y, p, R_ROOK, BLACK);
    p = createPiece(x, y, p, R_KNIGHT, BLACK);
    p = createPiece(x, y, p, R_BISHOP, BLACK);
    p = createPiece(x, y, p, QUEEN, BLACK);
    p = createPiece(x, y, p, KING, BLACK);
    for(i = 0; i < 8; i++) {
        p = createPiece(xp, y, p, PAWN, BLACK);
        xp = xp + X;
    }

    p = createPiece(x, y, p, L_ROOK, WHITE);
    p = createPiece(x, y, p, L_KNIGHT, WHITE);
    p = createPiece(x, y, p, L_BISHOP, WHITE);
    p = createPiece(x, y, p, R_ROOK, WHITE);
    p = createPiece(x, y, p, R_KNIGHT, WHITE);
    p = createPiece(x, y, p, R_BISHOP, WHITE);
    p = createPiece(x, y, p, QUEEN, WHITE);
    p = createPiece(x, y, p, KING, WHITE);
    xp = x;
    for(i = 0; i < 8; i++) {
        p = createPiece(xp, y, p, PAWN, WHITE);
        xp = xp + X;
    }
}