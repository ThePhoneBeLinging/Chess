//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"

class Queen : public Piece
{
public:
    Queen (int x, int y, bool white);

    bool isMoveLegal (int x, int y) override;

private:
};


#endif //CHESS_QUEEN_H
