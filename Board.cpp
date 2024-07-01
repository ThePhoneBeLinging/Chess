//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include "Board.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/King.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"

std::list<std::shared_ptr<Piece>> Board::_pieces;

std::list<std::shared_ptr<Piece>> Board::getPieces ()
{
    return Board::_pieces;
}

void Board::addPiece (std::shared_ptr<Piece> piece)
{
    if (piece == nullptr)
    {
        return;
    }
    Board::_pieces.push_back(piece);
}

std::shared_ptr<Piece> Board::pieceOnSquare (int x, int y)
{
    for (const std::shared_ptr<Piece> &piece: Board::_pieces)
    {
        if (piece->getX() == x && piece->getY() == y)
        {
            return piece;
        }
    }
    return nullptr;
}

void Board::startGame ()
{
    bool toMakeWhite = true;
    for (int i = 1; i < 9; i ++)
    {
        for (int k = 1; k < 9; k ++)
        {
            std::shared_ptr<Piece> ptr = nullptr;
            if (i == 5)
            {
                toMakeWhite = false;
            }
            if (i == 1 || i == 8)
            {
                if (k == 1 || k == 8)
                {
                    ptr = std::make_shared<Rook>(i, k, toMakeWhite);
                }
                else if (k == 2 || k == 7)
                {
                    ptr = std::make_shared<Knight>(i, k, toMakeWhite);
                }
                else if (k == 3 || k == 6)
                {
                    ptr = std::make_shared<Bishop>(i, k, toMakeWhite);
                }
                else if (k == 4)
                {
                    ptr = std::make_shared<King>(i, k, toMakeWhite);
                }
                else if (k == 5)
                {
                    ptr = std::make_shared<Queen>(i, k, toMakeWhite);
                }
            }
            else if (i == 2 || i == 7)
            {
                ptr = std::make_shared<Pawn>(i, k, toMakeWhite);
            }
            Board::addPiece(ptr);
        }
    }
}

void Board::removePiece (std::shared_ptr<Piece> piece)
{
    Board::_pieces.remove(piece);
}
