#include <iostream>
#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Board.h"
#include "raylib.h"
#include "UI.h"
#include "Engine.h"

int main ()
{
    InitWindow(1200, 800, "Dean");
    SetTargetFPS(60);
    UI *ui = new UI();
    Board::startGame();
    int winner = 0;
    while (! WindowShouldClose())
    {
        ui->draw();
        if (Board::getAllLegalMoves().empty())
        {
            if (Board::whiteTurn)
            {
                if (Board::isInCheck())
                {
                    winner = 1;
                }
            }
            else if (! Board::whiteTurn)
            {
                if (Board::isInCheck())
                {
                    winner = - 1;
                }
            }
            break;
        }
        Engine::getBestMove()->execute();
        if (! Board::whiteTurn)
        {

        }
    }
    CloseWindow();
    if (winner == 0)
    {
        std::cout << "Draw" << std::endl;
    }
    if (winner == 1)
    {
        std::cout << "White Wins" << std::endl;
    }
    if (winner == - 1)
    {
        std::cout << "Black Wins" << std::endl;
    }
    return 0;
}
