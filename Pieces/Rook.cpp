//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Rook.h"
#include "../Board.h"

Rook::Rook (int x, int y, bool white) :
        Piece(x, y, white)
{
    const char fileStart = white ? 'W' : 'B';
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cRook.png", fileStart);
    this->setTexture(LoadTexture(fileName));
}

bool Rook::isMoveLegal (int x, int y)
{
    if (! Piece::isMoveLegal(x, y))
    {
        return false;
    }
    if (this->getX() != x && this->getY() != y)
    {
        return false;
    }
    this->endX = x;
    this->endY = y;

    bool toMove = Piece::isMoveLegal(x, y);
    if (toMove)
    {
        Piece::move(x, y);
    }
    return toMove;
}

bool Rook::isMoveLegalRecursive (int x, int y)
{
    if (this->getX() != this->endX || this->getY() != this->endY)
    {
        if (Board::pieceOnSquare(x, y) != nullptr)
        {
            return false;
        }
    }
    int deltaX = x - this->getX();
    int deltaY = y - this->getY();
    if (deltaX == 0 && deltaY == 0)
    {
        return true;
    }
    if (deltaX != 0)
    {
        if (deltaX > 0)
        {
            deltaX = 1;
        }
        else
        {
            deltaX = - 1;
        }
    }
    if (deltaY != 0)
    {
        if (deltaY > 0)
        {
            deltaY = 1;
        }
        if (deltaY < 0)
        {
            deltaY = - 1;
        }
    }
    return isMoveLegalRecursive(x + deltaX, y + deltaY);
}
