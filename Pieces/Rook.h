//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "Piece.h"

class Rook : public Piece
{
public:
    Rook (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

protected:
    bool isMoveLegalRecursive (int x, int y);

    int endX;
    int endY;
};


#endif //CHESS_ROOK_H
