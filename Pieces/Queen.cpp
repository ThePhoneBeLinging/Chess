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
    const char fileStart = white ? 'W' : 'B';
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cQueen.png", fileStart);
    this->setTexture(LoadTexture(fileName));
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
