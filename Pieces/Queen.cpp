//
// Created by Elias Aggergaard Larsen on 01/07/2024.
//

#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen (int x, int y, bool white) :
        Piece(x, y, white)
{

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
