//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Pieces/Piece.h"
#include "Move.h"
#include <list>
#include <memory>

class Board
{
public:
    static std::list<std::shared_ptr<Piece>> getPieces ();

    static void addPiece (std::shared_ptr<Piece> piece);

    static void removePiece (std::shared_ptr<Piece> piece);

    static std::shared_ptr<Piece> pieceOnSquare (int x, int y);

    static void startGame ();

    static std::list<Move> getAllLegalMoves ();

    static std::list<Move> getAllLegalMovesForPiece (const std::shared_ptr<Piece> &piece);

    static bool whiteTurn;

    static void updateAllLegalMoves ();

private:
    static std::list<std::shared_ptr<Piece>> _pieces;
    static std::list<Move> _moves;
};


#endif //CHESS_BOARD_H
