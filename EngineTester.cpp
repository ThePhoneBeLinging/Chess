//
// Created by Elias Aggergaard Larsen on 16/07/2024.
//

#include "EngineTester.h"
#include "Board.h"
#include "V1Engine.h"
#include "UI.h"
#include <iostream>

EngineTester::EngineTester ()
{
    this->draws = 0;
    this->engine1Wins = 0;
    this->engine2Wins = 0;
}

int EngineTester::getDraws () const
{
    return draws;
}

int EngineTester::getEngine1Wins () const
{
    return engine1Wins;
}

int EngineTester::getEngine2Wins () const
{
    return engine2Wins;
}

void EngineTester::testEngines ()
{
    int movesSinceValueChange = 0;
    int lastValue = 0;
    UI *ui = new UI();
    while (! WindowShouldClose())
    {
        for (int i = 0; i < 500; i ++)
        {
            Board::startGame();
            std::cout << "Game nr " << i << std::endl;
            while (true)
            {
                Move *move;
                auto t1 = std::chrono::high_resolution_clock::now();
                if (Board::whiteTurn && i % 2 == 0)
                {
                    int amountOfMoves = Board::getAllLegalMoves().size();
                    move = V1Engine::getBestMove();
                    int totalTime = this->avgTimeUsed1 * movesMade1;
                    this->movesMade1 ++;
                    auto t2 = std::chrono::high_resolution_clock::now();
                    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
                    int timePerLegalMove = time.count();
                    totalTime += timePerLegalMove;
                    if (amountOfMoves >= 50)
                    { this->avgTimeUsed1 = totalTime / this->movesMade1; }
                }
                else
                {
                    int amountOfMoves = Board::getAllLegalMoves().size();
                    move = V1Engine::getBestMove();
                    int totalTime = this->avgTimeUsed2 * movesMade2;
                    this->movesMade2 ++;
                    auto t2 = std::chrono::high_resolution_clock::now();
                    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
                    int timePerLegalMove = time.count();
                    totalTime += timePerLegalMove;
                    if (amountOfMoves >= 50)
                    { this->avgTimeUsed2 = totalTime / this->movesMade2; }
                }


                ui->drawForEngineTester("V1", "V1", this->engine1Wins, this->engine2Wins, this->draws,
                                        this->avgTimeUsed1, this->avgTimeUsed2);
                move->execute();
                if (Board::getAllLegalMoves().empty() || movesSinceValueChange == 100)
                {
                    Board::whiteTurn = ! Board::whiteTurn;
                    if (Board::isInCheck() && movesSinceValueChange != 100)
                    {
                        if (Board::whiteTurn)
                        {
                            this->engine1Wins ++;
                        }
                        else
                        {
                            this->engine2Wins ++;
                        }
                    }
                    else
                    {
                        this->draws ++;
                    }
                    Board::whiteTurn = ! Board::whiteTurn;
                    movesSinceValueChange = 0;
                    lastValue = 0;
                    break;
                }
                int newVal = V1Engine::getPositionEvaluation();
                if (lastValue == newVal)
                { movesSinceValueChange ++; }
                else
                {
                    lastValue = newVal;
                    movesSinceValueChange = 0;
                }
            }
        }
    }
}
