//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <cstdlib>
#include "raylib.h"

class Piece
{
public:
    Piece (int x, int y, bool white);

    int getX () const;

    int getY () const;

    virtual void move (int x, int y);

    virtual bool isMoveLegal (int x, int y);

    bool isWhite () const;

    Texture2D getTexture ();

    void setTexture (Texture2D texture);

    bool isHasMoved () const;

    void setHasMoved (bool hasMoved);

    int getValue () const;

    void setValue (int value);

private:
    int _x;
    int _y;
    bool _white;
    Texture2D texture;
    bool hasMoved;
    int value;
};


#endif //CHESS_PIECE_H
