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
}

bool Queen::isMoveLegal (int x, int y)
{
    Piece *rook = new Rook(this->getX(), this->getY(), this->isWhite());
    Piece *bishop = new Bishop(this->getX(), this->getY(), this->isWhite());
    if (rook->isMoveLegal(x, y) || bishop->isMoveLegal(x, y))
    {
        return true;
    }
    delete rook;
    delete bishop;
    return false;
}
