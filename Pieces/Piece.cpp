//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Piece.h"
#include "../Board.h"
#include "../UI.h"

Piece::Piece (int x, int y, bool white)
{
    this->_x = x;
    this->_y = y;
    this->_white = white;
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
    if (Board::pieceOnSquare(x, y) != nullptr)
    {
        if (Board::pieceOnSquare(x, y)->isWhite() != this->_white)
        {
            Board::removePiece(Board::pieceOnSquare(x, y));
        }
        else
        {
            return;
        }
    }
    this->_x = x;
    this->_y = y;
    Board::whiteTurn = ! Board::whiteTurn;
}

bool Piece::isWhite () const
{
    return _white;
}

bool Piece::isMoveLegal (int x, int y)
{
    if (this->_white != Board::whiteTurn)
    { return false; }
    if (Board::pieceOnSquare(x, y) == nullptr)
    {
        return true;
    }
    if (Board::pieceOnSquare(x, y)->isWhite() == _white)
    {
        return false;
    }
    return true;
}

Texture2D Piece::getTexture ()
{
    return texture;
}

void Piece::setTexture (Texture2D texture)
{
    Piece::texture = texture;
    this->texture.height = UI::tileSize;
    this->texture.width = UI::tileSize;
}
