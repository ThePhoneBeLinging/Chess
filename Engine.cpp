//
// Created by Elias on 06/07/2024.
//

#include <memory>
#include <iostream>
#include "Engine.h"
#include "Pieces/Piece.h"
#include "Board.h"

int Engine::getPositionEvaluation ()
{
    int totalEval = calculateMaterialDifference();
    totalEval *= 10;
    return totalEval;
}

int Engine::calculateMaterialDifference ()
{
    int totalValue = 0;
    for (std::shared_ptr<Piece> piece: Board::getPieces())
    {
        if (piece->isWhite())
        {
            totalValue += piece->getValue();
        }
        else
        {
            totalValue -= piece->getValue();
        }
    }
    return totalValue;
}

Move *Engine::getBestMove ()
{
    int maxDepth = 2;
    int minRating = INT32_MAX;
    int maxRating = INT32_MIN;
    int indexOfMin = 0;
    int indexOfMax = 0;
    int k = 0;
    for (Move move: Board::getAllLegalMoves())
    {
        move.execute();
        int rating = recursiveMoveCalc(0, maxDepth);
        if (rating > maxRating)
        {
            maxRating = rating;
            indexOfMax = k;
        }
        if (minRating > rating)
        {
            minRating = rating;
            indexOfMin = k;
        }
        k ++;
        move.undo();
    }
    int index = 0;

    std::list<Move> moves = Board::getAllLegalMoves();
    for (Move move: moves)
    {
        if (Board::whiteTurn)
        {
            if (index == indexOfMax)
            { return move.getMovePointerFromMove(); }
        }
        else
        {
            if (index == indexOfMin)
            {
                return move.getMovePointerFromMove();
            }
        }
        index ++;
    }

    return nullptr;
}

int Engine::recursiveMoveCalc (int depth, int maxDepth)
{
    if (depth == maxDepth)
    {
        return getPositionEvaluation();
    }
    int min = INT32_MAX;
    int max = INT32_MIN;
    std::list<Move> moves = Board::getAllLegalMoves();
    for (Move move: moves)
    {
        move.execute();
        int moveValue = recursiveMoveCalc(depth + 1, maxDepth);
        if (moveValue > max)
        {
            max = moveValue;
        }
        if (moveValue < min)
        {
            min = moveValue;
        }
        move.undo();
    }
    if (Board::whiteTurn)
    { return max; }
    else
    { return min; }
}
