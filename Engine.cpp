//
// Created by Elias on 06/07/2024.
//

#include <memory>
#include "Engine.h"
#include "Pieces/Piece.h"
#include "Board.h"

int Engine::getPositionEvaluation ()
{
    int totalEval = calculateMaterialDifference();
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
    int minRating = - 33333;
    int maxRating = - 33333;
    int indexOfMin = 0;
    int indexOfMax = 0;
    int k = 0;
    Board::updateAllLegalMoves();
    for (Move move: Board::getAllLegalMoves())
    {
        move.execute();
        int rating = recursiveMoveCalc(0, maxDepth);
        if (rating > maxRating || maxRating == - 33333)
        {
            maxRating = rating;
            indexOfMax = k;
        }
        if (minRating > rating || minRating == - 33333)
        {
            minRating = rating;
            indexOfMin = k;
        }
        k ++;
        move.undo();
    }
    int index = 0;
    for (Move move: Board::getAllLegalMoves())
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
    int max = - 333333;
    int min = - 333333;
    for (Move move: Board::getAllLegalMoves())
    {
        move.execute();
        int moveValue = recursiveMoveCalc(depth + 1, maxDepth);
        if (moveValue > max || max == - 33333)
        {
            max = moveValue;
        }
        if (moveValue < min || min == - 33333)
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
