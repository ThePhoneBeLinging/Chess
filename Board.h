//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Pieces/Piece.h"
#include <list>

class Board
{
public:
    static std::list<Piece*> getPieces();
    static void addPiece(Piece* piece);
    static Piece* pieceOnSquare(int x, int y);
private:
    static std::list<Piece*> _pieces;
};


#endif //CHESS_BOARD_H
