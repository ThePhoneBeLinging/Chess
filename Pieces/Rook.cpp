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
    int deltaX = this->getX() - x;
    int deltaY = this->getY() - y;
    if (deltaX != 0 && deltaY != 0)
    {
        return false;
    }
    if (deltaX > 0)
    { deltaX = 1; }
    else if (deltaX != 0)
    { deltaX = - 1; }
    if (deltaY > 0)
    { deltaY = 1; }
    else if (deltaY != 0)
    { deltaY = - 1; }
    if (! Piece::isMoveLegal(x, y))
    { return false; }
    x += deltaX;
    y += deltaY;
    return isMoveLegalRecursive(x, y);
}

bool Rook::isMoveLegalRecursive (int x, int y)
{
    if (x == this->getX() && y == this->getY())
    {
        return true;
    }
    if (Board::pieceOnSquare(x, y) != nullptr)
    {
        return false;
    }
    int deltaX = this->getX() - x;
    int deltaY = this->getY() - y;
    if (deltaX > 0)
    { deltaX = 1; }
    else if (deltaX != 0)
    { deltaX = - 1; }
    if (deltaY > 0)
    { deltaY = 1; }
    else if (deltaY != 0)
    { deltaY = - 1; }
    return isMoveLegalRecursive(x + deltaX, y + deltaY);
}
