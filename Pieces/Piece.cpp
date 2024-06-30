//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Piece.h"
#include "../Board.h"

Piece::Piece (int x, int y, bool white)
{
    this->_x = x;
    this->_y = y;
    this->_white = white;
    Board::addPiece(this);
}

int Piece::getX () const
{
    return _x;
}

int Piece::getY () const
{
    return _y;
}

void Piece::move (int x, int y)
{
    this->_x = x;
    this->_y = y;
}

bool Piece::isWhite () const
{
    return _white;
}

bool Piece::isMoveLegal (int x, int y)
{
    if (Board::pieceOnSquare(x, y) == nullptr)
    {
        return true;
    }
    if (Board::pieceOnSquare(x, y)->isWhite() == _white)
    { return false; }
    return true;
}
