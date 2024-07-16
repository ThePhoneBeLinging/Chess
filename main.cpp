#include <iostream>
#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Board.h"
#include "raylib.h"
#include "UI.h"
#include "Engines/V1Engine.h"
#include "EngineTester.h"
#include "Engines/V2Engine.h"

int main ()
{
    bool toTestEngines = true;
    srand(time(nullptr));
    InitWindow(1200, 800, "Dean");
    SetTargetFPS(60);
    UI *ui = new UI();
    TextureManager::loadTextures();
    Board::startGame();
    int winner = 5;
    if (toTestEngines)
    {
        auto engineTester = new EngineTester();
        engineTester->testEngines();
        std::cout << engineTester->getDraws();
    }
    while (! WindowShouldClose())
    {
        if (toTestEngines)
        { break; }
        ui->draw();
        if (Board::getAllLegalMoves().empty())
        {
            Board::whiteTurn = ! Board::whiteTurn;
            if (Board::isInCheck())
            {
                if (Board::whiteTurn)
                {
                    winner = 1;
                }
                else
                {
                    winner = - 1;
                }
            }
            Board::whiteTurn = ! Board::whiteTurn;
            break;
        }
        if (! Board::whiteTurn)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            Move *bestMove = V2Engine::getBestMove();
            auto t2 = std::chrono::high_resolution_clock::now();
            int amountOfMoves = Board::getAllLegalMoves().size();
            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
            std::cout << "Time per move: " << time.count() / amountOfMoves << std::endl;
            std::cout << "Number of moves: " << amountOfMoves << std::endl;
            std::cout << "Time to search: " << time.count() << std::endl;
            std::cout << std::endl << std::endl << std::endl;
            bestMove->execute();
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
