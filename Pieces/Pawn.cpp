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
    if (this->getX() != x && Board::pieceOnSquare(x,y) == nullptr) return false;


    if (std::abs(x - this->getX()) > 1)
    {
        return false;
    }

    if (!Piece::isMoveLegal(x,y)) return false;

    if (std::abs(x - this->getX()) > 0)
    {
        if (Board::pieceOnSquare(x, y) != nullptr && Board::pieceOnSquare(x, y)->isWhite() != this->isWhite())
        {
            return true;
        }
    }

    if (this->isWhite() && this->getY() == 2 && ! this->isHasMoved())
    {
        if (y == 4 && Board::pieceOnSquare(x, 3) == nullptr && this->getX() == x)
        {
            return true;
        }
    }
    else if (! this->isWhite() && this->getY() == 7 && ! this->isHasMoved())
    {
        if (y == 5 && Board::pieceOnSquare(x, 6) == nullptr && this->getX() == x)
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
