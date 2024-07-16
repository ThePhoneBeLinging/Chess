//
// Created by Elias on 06/07/2024.
//

#include <memory>
#include <iostream>
#include "V2Engine.h"
#include "../Pieces/Piece.h"
#include "../Board.h"

int V2Engine::getPositionEvaluation ()
{
    int totalEval = calculateMaterialDifference();
    totalEval *= 10;
    return totalEval;
}

int V2Engine::calculateMaterialDifference ()
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

Move *V2Engine::getBestMove ()
{
    int maxDepth = 0;
    int minRating = INT32_MAX;
    int maxRating = INT32_MIN;
    std::list<Move> minMoves;
    std::list<Move> maxMoves;
    std::list<Move> moves = Board::getAllLegalMoves();
    return moves.begin()->getMovePointerFromMove();
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
        int value = rand() % maxMoves.size();
        auto maxIterator = maxMoves.begin();
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

int V2Engine::recursiveMoveCalc (int depth, int maxDepth)
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
    for (Move move: legalMoves)
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
