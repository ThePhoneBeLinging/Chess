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
    std::list<Move> minMoves;
    std::list<Move> maxMoves;
    std::list<Move> moves = Board::getAllLegalMoves();
    for (Move move: moves)
    {
        move.execute();
        int rating = recursiveMoveCalc(0, maxDepth);
        if (rating > maxRating)
        {
            maxRating = rating;
            maxMoves.clear();
        }
        if (minRating > rating)
        {
            minRating = rating;
            minMoves.clear();
        }
        if (rating == maxRating)
        {
            maxMoves.push_back(move);
        }
        if (rating == minRating)
        {
            minMoves.push_back(move);
        }
        move.undo();
    }
    if (maxMoves.empty() || minMoves.empty())
    {
        return nullptr;
    }
    if (Board::whiteTurn)
    {
        auto maxIterator = maxMoves.begin();
        for (int i = 0; i < rand() % maxMoves.size(); i ++)
        {
            maxIterator ++;
        }
        return maxIterator->getMovePointerFromMove();
    }
    else
    {
        auto minIterator = minMoves.begin();
        for (int i = 0; i < rand() % minMoves.size(); i ++)
        {
            minIterator ++;
        }
        return minIterator->getMovePointerFromMove();
    }
}

int Engine::recursiveMoveCalc (int depth, int maxDepth)
{
    if (depth == maxDepth)
    {
        return getPositionEvaluation();
    }
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (Move move: Board::getAllLegalMoves())
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
