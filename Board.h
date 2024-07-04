//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Pieces/Piece.h"
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

    static bool whiteTurn;

private:
    static std::list<std::shared_ptr<Piece>> _pieces;
};


#endif //CHESS_BOARD_H
