//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "King.h"
#include "../Board.h"
#include <cstdlib>
#include <cstdio>

King::King (int x, int y, bool white) :
        Piece(x, y, white)
{
    const char fileStart = white ? 'W' : 'B';
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cKing.png", fileStart);
    this->setTexture(LoadTexture(fileName));
    this->setValue(0);
}

bool King::isMoveLegal (int x, int y)
{
    if (! Piece::isMoveLegal(x, y))
    { return false; }
    int deltaX = std::abs(x - this->getX());
    int deltaY = std::abs(y - this->getY());

    //Castle check
    if (! this->isHasMoved())
    {
        int rookX = 0;
        bool kingSideCastle = false;
        if (x == this->getX() - 2 && y == this->getY())
        {
            rookX = 1;
            kingSideCastle = false;
        }
        else if (x == this->getX() + 2 && y == this->getY())
        {
            rookX = 8;
            kingSideCastle = true;
        }
        std::shared_ptr<Piece> rook = Board::pieceOnSquare(rookX, y);
        if (rook != nullptr)
        {
            if (kingSideCastle)
            {
                if (rook->isMoveLegal(this->getX() + 1, this->getY()))
                {
                    return true;
                }
            }
            else
            {
                if (rook->isMoveLegal(this->getX() - 1, this->getY()))
                {
                    return true;
                }
            }
        }
    }

    if (deltaX > 1 || deltaY > 1)
    { return false; }
    return Piece::isMoveLegal(x, y);
}

std::list<Move> King::getLegalMoves ()
{
    std::list<Move> legalMoves;
    for (int i = - 2; i < 3; i ++)
    {
        for (int k = - 1; k < 2; k ++)
        {
            if (isMoveLegal(this->getX() + i, this->getY() + k))
            {
                legalMoves.emplace_back(this->getX(), this->getY(), this->getX() + i, this->getY() + k);
            }
        }
    }

    return legalMoves;
}

