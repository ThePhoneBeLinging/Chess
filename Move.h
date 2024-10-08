//
// Created by Elias on 05/07/2024.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H


#include <memory>
#include <list>
#include "Pieces/Piece.h"

class Move
{
public:
    Move (int xFrom, int yFrom, int xTo, int yTo);

    int getXFrom () const;

    void setXFrom (int xFrom);

    int getXTo () const;

    void setXTo (int xTo);

    int getYFrom () const;

    void setYFrom (int yFrom);

    int getYTo () const;

    void setYTo (int yTo);

    void execute ();

    void undo ();

    Move *getMovePointerFromMove () const;

    bool equals (Move move);

    bool isCapture ();

private:
    int _xFrom;
    int _xTo;
    int _yFrom;
    int _yTo;
    int _rookFromX;
    int _rookToX;
    int pieceToMoveHadMoved = false;
    std::shared_ptr<Piece> pieceToMove;
    std::shared_ptr<Piece> pieceToCapture;
    std::shared_ptr<Piece> rookInvolvedInCastle;
    std::shared_ptr<Piece> queenCreated;
};


#endif //CHESS_MOVE_H
