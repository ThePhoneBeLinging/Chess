//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#include <cstdio>
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen (int x, int y, bool white) :
        Piece(x, y, white)
{
    if (white)
    { this->setTexture(TextureManager::wQueen); }
    else
    { this->setTexture(TextureManager::bQueen); }
    this->mRook = new Rook(this->getX(), this->getY(), this->isWhite());
    this->mBishop = new Bishop(this->getX(), this->getY(), this->isWhite());
    this->setValue(9);
}

bool Queen::isMoveLegal (int x, int y)
{
    if (mRook->isMoveLegal(x, y) || mBishop->isMoveLegal(x, y))
    {
        return true;
    }
    return false;
}

void Queen::move (int x, int y)
{
    mRook->move(x, y);
    mBishop->move(x, y);
    Piece::move(x, y);
}

std::list<Move> Queen::getLegalMoves ()
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
