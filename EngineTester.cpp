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
                if (Board::whiteTurn && i % 2 == 0)
                {
                    move = V1Engine::getBestMove();
                }
                else
                {
                    move = V1Engine::getBestMove();
                }
                ui->drawForEngineTester("V1", "V1", this->engine1Wins, this->engine2Wins, this->draws);
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
