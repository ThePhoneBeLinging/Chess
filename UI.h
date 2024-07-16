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

    void drawForEngineTester (std::string engine1, std::string engine2, int winsEngine1, int winsEngine2, int draws);

    static int tileSize;
private:
    std::shared_ptr<Piece> pieceOnHand;

    std::shared_ptr<Piece> selectedPiece;

    void onClick (Vector2 position);

    void onRelease (Vector2 position);
};


#endif //CHESS_UI_H
