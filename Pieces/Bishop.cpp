//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#include "Bishop.h"
#include "../Board.h"

Bishop::Bishop (int x, int y, bool white) :
        Piece(x, y, white)
{

}

bool Bishop::isMoveLegal (int x, int y)
{
    this->endX = x;
    this->endY = y;
    int deltaX = this->getX() - x;
    int deltaY = this->getY() - y;
    if (std::abs(deltaX) != std::abs(deltaY))
    {
        return false;
    }
    if (Board::pieceOnSquare(x, y) != nullptr && Board::pieceOnSquare(x, y)->isWhite() == this->isWhite())
    {
        return false;
    }
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
    return isMoveLegalRecursive(x + deltaX, y + deltaY);
}
