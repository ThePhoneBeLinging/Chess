#include <iostream>
#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Board.h"
#include "raylib.h"
#include "UI.h"

int main ()
{
    InitWindow(1200, 800, "Dean");
    SetTargetFPS(60);
    UI *ui = new UI();
    Board::startGame();
    while (! WindowShouldClose())
    {
        ui->draw();
    }
    CloseWindow();
    return 0;
}
