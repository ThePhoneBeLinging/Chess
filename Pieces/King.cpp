//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "King.h"
#include <cstdlib>
King::King (int x, int y, bool white) :
        Piece(x, y, white)
{
}

bool King::isMoveLegal (int x, int y)
{
    int deltaX = std::abs(x - this->getX());
    int deltaY = std::abs(y - this->getY());

    if (deltaX > 1 || deltaY > 1) return false;
    return Piece::isMoveLegal(x, y);
}
