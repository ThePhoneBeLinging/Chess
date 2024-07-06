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
    this->setValue(1);
}

bool Pawn::isMoveLegal (int x, int y)
{
    if (this->getX() == x && Board::pieceOnSquare(x, y) != nullptr)
    {
        return false;
    }
    if (this->getX() != x && Board::pieceOnSquare(x, y) == nullptr)
    { return false; }


    if (std::abs(x - this->getX()) > 1)
    {
        return false;
    }

    if (! Piece::isMoveLegal(x, y))
    { return false; }

    if (std::abs(x - this->getX()) > 0 && std::abs(y - this->getY()) == 1)
    {
        if ((this->isWhite() && this->getY() - y == - 1) || (! this->isWhite() && this->getY() - y == 1))
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

    if (this->isWhite() && y - 1 == this->getY() && this->getX() == x)
    {
        return true;
    }
    else if (! this->isWhite())
    {
        if (y + 1 == this->getY() && this->getX() == x)
        {
            return true;
        }
    }
    return false;
}

std::list<Move> Pawn::getLegalMoves ()
{
    std::list<Move> legalMoves;
    for (int i = 1; i < 9; i ++)
    {
        for (int k = 1; k < 9; k ++)
        {
            if (isMoveLegal(i, k))
            {
                legalMoves.emplace_back(this->getX(), this->getY(), i, k);
            }
        }
    }

    return legalMoves;
}
