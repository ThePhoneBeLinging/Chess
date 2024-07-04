//
// Created by Elias Aggergaard Larsen on 03/07/2024.
//

#ifndef CHESS_UI_H
#define CHESS_UI_H

#include "Board.h"
#include <cstdlib>
#include <iostream>

class UI
{
public:
    UI ();

    void draw ();

    static int tileSize;
private:
    std::shared_ptr<Piece> pieceOnHand;

    void onClick (Vector2 position);

    void onRelease (Vector2 position);
};


#endif //CHESS_UI_H
