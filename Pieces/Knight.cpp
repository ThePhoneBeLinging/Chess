//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include <cstdio>
#include "Knight.h"

Knight::Knight (int x, int y, bool white) :
        Piece(x, y, white)
{
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cKnight.png", white ? 'W' : 'B');
    this->setTexture(LoadTexture(fileName));
    this->setValue(3);
}

bool Knight::isMoveLegal (int x, int y)
{
    if (! Piece::isMoveLegal(x, y))
    { return false; }
    int deltaX = std::abs(x - this->getX());
    int deltaY = std::abs(y - this->getY());

    if (deltaX == 2 && deltaY == 1 || deltaX == 1 && deltaY == 2)
    {
        return Piece::isMoveLegal(x, y);
    }
    return false;
}

