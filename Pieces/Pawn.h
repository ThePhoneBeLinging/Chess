//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

private:
};


#endif //CHESS_PAWN_H
