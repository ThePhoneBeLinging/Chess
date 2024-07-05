//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#include "Bishop.h"
#include "../Board.h"

Bishop::Bishop (int x, int y, bool white) :
        Piece(x, y, white)
{
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cBishop.png", white ? 'W' : 'B');
    this->setTexture(LoadTexture(fileName));
}

bool Bishop::isMoveLegal (int x, int y)
{
    int deltaX = this->getX() - x;
    int deltaY = this->getY() - y;
    if (std::abs(deltaX) != std::abs(deltaY))
    {
        return false;
    }
    if (deltaX > 0)
    { deltaX = 1; }
    else
    { deltaX = - 1; }
    if (deltaY > 0)
    { deltaY = 1; }
    else
    { deltaY = - 1; }
    if (! Piece::isMoveLegal(x, y))
    { return false; }
    x += deltaX;
    y += deltaY;
    return isMoveLegalRecursive(x, y);
}

bool Bishop::isMoveLegalRecursive (int x, int y)
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
    else
    { deltaX = - 1; }
    if (deltaY > 0)
    { deltaY = 1; }
    else
    { deltaY = - 1; }
    return isMoveLegalRecursive(x + deltaX, y + deltaY);
}
