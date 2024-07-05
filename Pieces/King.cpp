//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "King.h"
#include <cstdlib>
#include <cstdio>

King::King (int x, int y, bool white) :
        Piece(x, y, white)
{
    const char fileStart = white ? 'W' : 'B';
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cKing.png", fileStart);
    this->setTexture(LoadTexture(fileName));
}

bool King::isMoveLegal (int x, int y)
{
    if (!Piece::isMoveLegal(x,y)) return false;
    int deltaX = std::abs(x - this->getX());
    int deltaY = std::abs(y - this->getY());

    if (deltaX > 1 || deltaY > 1)
    { return false; }
    return Piece::isMoveLegal(x, y);
}
