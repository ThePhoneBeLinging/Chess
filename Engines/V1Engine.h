//
// Created by Elias on 06/07/2024.
//

#ifndef CHESS_V1ENGINE_H
#define CHESS_V1ENGINE_H


#include "../Move.h"

class V1Engine
{
public:
    static int calculateMaterialDifference ();

    static int getPositionEvaluation ();

    static Move *getBestMove (int maxDepth);

    static int recursiveMoveCalc (int depth, int maxDepth);
};


#endif //CHESS_V1ENGINE_H
