//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Piece.h"

class King : public Piece
{
public:
    King (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

    std::list<Move> getLegalMoves () override;
};


#endif //CHESS_KING_H
