//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

protected:
    bool isMoveLegalRecursive (int x, int y);
};


#endif //CHESS_BISHOP_H
