//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Board.h"
std::list<Piece*> Board::_pieces;

std::list<Piece *> Board::getPieces ()
{
    return Board::_pieces;
}

void Board::addPiece (Piece *piece)
{
    Board::_pieces.push_back(piece);
}

Piece *Board::pieceOnSquare (int x, int y)
{
    for (Piece* piece : Board::_pieces)
    {
        if (piece->getX() == x && piece->getY() == y) return piece;
    }
    return nullptr;
}
