//
// Created by Elias on 06/07/2024.
//

#ifndef CHESS_V2ENGINE_H
#define CHESS_V2ENGINE_H


#include "../Move.h"

class V2Engine
{
public:
    static int calculateMaterialDifference ();

    static int getPositionEvaluation ();

    static Move *getBestMove ();

    static int recursiveMoveCalc (int depth, int maxDepth);
};


#endif //CHESS_V2ENGINE_H
