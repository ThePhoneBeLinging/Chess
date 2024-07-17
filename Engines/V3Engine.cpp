//
// Created by Elias on 06/07/2024.
//

#include <memory>
#include <iostream>
#include "V3Engine.h"
#include "../Pieces/Piece.h"
#include "../Board.h"

int V3Engine::getPositionEvaluation ()
{
    int totalEval = calculateMaterialDifference();
    //totalEval *= 100;
    return totalEval;
}

int V3Engine::calculateMaterialDifference ()
{
    int totalValue = 0;
    for (std::shared_ptr<Piece> piece: Board::getPieces())
    {
        if (piece->isWhite())
        {
            totalValue += piece->getValue() * 10;
            totalValue += piece->getLegalMoves().size();
        }
        else
        {
            totalValue -= piece->getValue() * 10;
            totalValue -= piece->getLegalMoves().size();
        }
    }
    return totalValue;
}

Move *V3Engine::getBestMove ()
{
    int maxDepth = 1;
    int minRating = INT32_MAX;
    int maxRating = INT32_MIN;
    std::list<Move> minMoves;
    std::list<Move> maxMoves;
    std::list<Move> moves = Board::getAllLegalMoves();
    for (Move move: moves)
    {
        move.execute();
        int rating = recursiveMoveCalc(0, maxDepth, minRating, maxRating);
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
        int value = rand() % maxMoves.size();
        for (int i = 0; i < value; i ++)
        {
            maxIterator ++;
        }
        return maxIterator->getMovePointerFromMove();
    }
    else
    {
        auto minIterator = minMoves.begin();
        int value = rand() % minMoves.size();
        for (int i = 0; i < value; i ++)
        {
            minIterator ++;
        }
        return minIterator->getMovePointerFromMove();
    }
}

int V3Engine::recursiveMoveCalc (int depth, int maxDepth, int minFound, int maxFound)
{
    if (depth == maxDepth)
    {
        return getPositionEvaluation();
    }
    int min = INT32_MAX;
    int max = INT32_MIN;
    std::list<Move> legalMoves = Board::getAllLegalMoves();
    if (legalMoves.empty())
    {
        Board::whiteTurn = ! Board::whiteTurn;
        if (Board::isInCheck())
        {
            Board::whiteTurn = ! Board::whiteTurn;
            if (Board::whiteTurn)
            {
                return INT32_MIN;
            }
            else
            {
                return INT32_MAX;
            }
        }
        Board::whiteTurn = ! Board::whiteTurn;
        return 0;
    }
    std::list<Move> updatedLegalMoves;
    for (Move move: legalMoves)
    {
        if (! move.isCapture())
        {
            updatedLegalMoves.push_back(move);
        }
    }
    for (Move move: legalMoves)
    {
        if (move.isCapture())
        {
            updatedLegalMoves.push_back(move);
        }
    }
    for (Move move: updatedLegalMoves)
    {
        move.execute();
        int moveValue = recursiveMoveCalc(depth + 1, maxDepth, min, max);
        if (moveValue > max)
        {
            max = moveValue;
        }
        if (moveValue < min)
        {
            min = moveValue;
        }
        move.undo();
        if (minFound > min && ! Board::whiteTurn && minFound != INT32_MAX)
        {
            //min = INT32_MIN;
            //break;
        }
        if (maxFound < max && Board::whiteTurn && maxFound != INT32_MIN)
        {
            //max = INT32_MAX;
            //break;
        }
    }
    if (Board::whiteTurn)
    { return max; }
    else
    { return min; }
}
