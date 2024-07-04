//
// Created by Elias Aggergaard Larsen on 03/07/2024.
//

#ifndef CHESS_UI_H
#define CHESS_UI_H

#include "Board.h"
#include <cstdlib>

class UI
{
public:
    UI ();

    void draw ();

    static int tileSize;
private:
    std::shared_ptr<Piece> pieceOnHand;
};


#endif //CHESS_UI_H
