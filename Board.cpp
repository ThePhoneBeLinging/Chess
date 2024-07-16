//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include <iostream>
#include "Board.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/King.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"

std::list<std::shared_ptr<Piece>> Board::_pieces;
std::list<Move> Board::_moves;
bool Board::whiteTurn = true;
int Board::amountOfCalls;

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
    Board::_pieces.clear();
    for (int i = 8; i > 0; i --)
    {
        for (int k = 8; k > 0; k --)
        {
            std::shared_ptr<Piece> ptr = nullptr;
            bool toMakeWhite = k < 5;
            if (k == 1 || k == 8)
            {
                if (i == 1 || i == 8)
                {
                    ptr = std::make_shared<Rook>(i, k, toMakeWhite);
                }
                else if (i == 2 || i == 7)
                {
                    ptr = std::make_shared<Knight>(i, k, toMakeWhite);
                }
                else if (i == 3 || i == 6)
                {
                    ptr = std::make_shared<Bishop>(i, k, toMakeWhite);
                }
                else if (i == 4)
                {
                    ptr = std::make_shared<Queen>(i, k, toMakeWhite);
                }
                else if (i == 5)
                {
                    ptr = std::make_shared<King>(i, k, toMakeWhite);
                }
            }
            else if (k == 2 || k == 7)
            {
                ptr = std::make_shared<Pawn>(i, k, toMakeWhite);
            }
            Board::addPiece(ptr);
        }
    }
    Board::updateAllLegalMoves();
}

void Board::removePiece (std::shared_ptr<Piece> piece)
{
    Board::_pieces.remove(piece);
}

std::list<Move> Board::getAllLegalMoves ()
{
    updateAllLegalMoves();
    return Board::_moves;
}

void Board::updateAllLegalMoves ()
{
    Board::_moves.clear();
    auto pieces = Board::getPieces();
    for (auto piece: pieces)
    {
        if (piece->isWhite() != whiteTurn)
        { continue; }
        std::list<Move> moves = piece->getLegalMoves();
        for (Move move: moves)
        {
            move.execute();
            if (! Board::isInCheck())
            {
                Board::_moves.push_back(move);
            }
            move.undo();
        }
    }
}

bool Board::isInCheck ()
{
    bool inCheck = false;
    auto pieces = Board::getPieces();
    for (auto king: pieces)
    {
        if (king->isWhite() == Board::whiteTurn)
        { continue; }
        if (king->getValue() == 0)
        {
            for (auto otherPiece: pieces)
            {
                if (otherPiece->isWhite() != Board::whiteTurn)
                { continue; }
                if (otherPiece->isMoveLegal(king->getX(), king->getY()))
                {
                    inCheck = true;
                    break;
                }
            }
            break;
        }
    }
    return inCheck;
}
