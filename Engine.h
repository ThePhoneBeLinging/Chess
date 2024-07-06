//
// Created by Elias on 06/07/2024.
//

#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H


#include "Move.h"

class Engine
{
public:
    static int calculateMaterialDifference ();

    static int getPositionEvaluation ();

    static Move *getBestMove ();

    static int recursiveMoveCalc (int depth, int maxDepth);
};


#endif //CHESS_ENGINE_H
