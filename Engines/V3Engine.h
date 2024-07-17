//
// Created by Elias on 06/07/2024.
//

#ifndef CHESS_V3ENGINE_H
#define CHESS_V3ENGINE_H


#include "../Move.h"

class V3Engine
{
public:
    static int calculateMaterialDifference ();

    static int getPositionEvaluation ();

    static Move *getBestMove (int maxDepth);

    static int recursiveMoveCalc (int depth, int maxDepth, int minFound, int maxFound);
};


#endif //CHESS_V3ENGINE_H
