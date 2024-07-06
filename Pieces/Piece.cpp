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
    this->hasMoved = false;
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
    this->hasMoved = true;
    Board::updateAllLegalMoves();
}

bool Piece::isWhite () const
{
    return _white;
}

bool Piece::isMoveLegal (int x, int y)
{
    if (y > 8 || y < 1)
    { return false; }
    if (x > 8 || x < 1)
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

bool Piece::isHasMoved () const
{
    return hasMoved;
}

void Piece::setHasMoved (bool hasMoved)
{
    Piece::hasMoved = hasMoved;
}

int Piece::getValue () const
{
    return value;
}

void Piece::setValue (int value)
{
    Piece::value = value;
}
