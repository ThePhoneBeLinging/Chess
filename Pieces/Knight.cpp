//
// Created by Elias Aggergaard Larsen on 30/06/2024.
//

#include <cstdio>
#include <iostream>
#include "Knight.h"

Knight::Knight (int x, int y, bool white) :
        Piece(x, y, white)
{
    char fileName[50];
    snprintf(fileName, 50, "../Resources/ChessPieces/%cKnight.png", white ? 'W' : 'B');
    this->setTexture(LoadTexture(fileName));
    this->setValue(3);
}

bool Knight::isMoveLegal (int x, int y)
{
    if (! Piece::isMoveLegal(x, y))
    { return false; }
    int deltaX = std::abs(x - this->getX());
    int deltaY = std::abs(y - this->getY());

    if (deltaX == 2 && deltaY == 1 || deltaX == 1 && deltaY == 2)
    {
        return Piece::isMoveLegal(x, y);
    }
    return false;
}

std::list<Move> Knight::getLegalMoves ()
{
    std::list<Move> legalMoves;
    std::list<int> possibleValues;
    possibleValues.push_back(- 1);
    possibleValues.push_back(- 2);
    possibleValues.push_back(1);
    possibleValues.push_back(2);
    for (int x: possibleValues)
    {
        for (int y: possibleValues)
        {
            if (isMoveLegal(this->getX() + x, this->getY() + y))
            {
                legalMoves.emplace_back(this->getX(), this->getY(), this->getX() + x, this->getY() + y);
            }
        }
    }


    return legalMoves;
}
