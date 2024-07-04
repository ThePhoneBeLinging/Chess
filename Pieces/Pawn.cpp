//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Pawn.h"
#include "../Board.h"

Pawn::Pawn (int x, int y, bool white) :
        Piece(x, y, white)
{
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cPawn.png", white ? 'W' : 'B');
    this->setTexture(LoadTexture(fileName));
}

bool Pawn::isMoveLegal (int x, int y)
{
    if (this->getX() == x && Board::pieceOnSquare(x, y) != nullptr)
    {
        return false;
    }

    if (std::abs(x - this->getX()) > 1)
    {
        return false;
    }

    if (std::abs(x - this->getX()) > 0)
    {
        if (Board::pieceOnSquare(x, y) != nullptr && Board::pieceOnSquare(x, y)->isWhite() != this->isWhite())
        {
            return true;
        }
    }

    if (this->isWhite() && this->getY() == 2 && ! this->hasMoved)
    {
        if (y == 4 && Board::pieceOnSquare(x, 3) == nullptr && this->getX() == x)
        {
            return true;
        }
    }

    if (this->isWhite() && y - 1 == this->getY())
    {
        return true;
    }
    else
    {
        if (y + 1 == this->getY())
        {
            return true;
        }
    }
    return false;
}

bool Pawn::isHasMoved () const
{
    return hasMoved;
}

void Pawn::setHasMoved (bool hasMoved)
{
    Pawn::hasMoved = hasMoved;
}

void Pawn::move (int x, int y)
{
    this->hasMoved = true;
    Piece::move(x, y);
}
