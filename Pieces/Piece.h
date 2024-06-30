//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <cstdlib>
class Piece
{
public:
    Piece(int x, int y, bool white);

    int getX () const;

    int getY () const;

    void move(int x, int y);

    virtual bool isMoveLegal(int x, int y);

    bool isWhite () const;

private:
    int _x;
    int _y;
    bool _white;
};


#endif //CHESS_PIECE_H
