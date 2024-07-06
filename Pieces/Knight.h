//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Piece.h"

class Knight : public Piece
{
public:
    Knight (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

    std::list<Move> getLegalMoves () override;
};


#endif //CHESS_KNIGHT_H
