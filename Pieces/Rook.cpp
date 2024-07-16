//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Rook.h"
#include "../Board.h"

Rook::Rook (int x, int y, bool white) :
        Piece(x, y, white)
{
    if (white)
    { this->setTexture(TextureManager::wRook); }
    else
    { this->setTexture(TextureManager::bRook); }
    this->setValue(5);
}

bool Rook::isMoveLegal (int x, int y)
{
    if (! Piece::isMoveLegal(x, y))
    { return false; }
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

std::list<Move> Rook::getLegalMoves ()
{
    std::list<Move> legalMoves;
    for (int i = 1; i < 9; i ++)
    {
        if (isMoveLegal(i, this->getY()))
        {
            legalMoves.emplace_back(this->getX(), this->getY(), i, this->getY());
        }
    }
    for (int k = 1; k < 9; k ++)
    {
        if (isMoveLegal(this->getX(), k))
        {
            legalMoves.emplace_back(this->getX(), this->getY(), this->getX(), k);
        }
    }

    return legalMoves;
}
