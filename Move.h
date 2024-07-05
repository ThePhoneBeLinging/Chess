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

private:
    int _xFrom;
    int _xTo;
    int _yFrom;
    int _yTo;
};


#endif //CHESS_MOVE_H
