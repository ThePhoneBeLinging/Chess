//
// Created by Elias on 05/07/2024.
//

#include "Move.h"
#include "Board.h"

int Move::getXFrom () const
{
    return _xFrom;
}

void Move::setXFrom (int xFrom)
{
    Move::_xFrom = xFrom;
}

int Move::getXTo () const
{
    return _xTo;
}

void Move::setXTo (int xTo)
{
    Move::_xTo = xTo;
}

int Move::getYFrom () const
{
    return _yFrom;
}

void Move::setYFrom (int yFrom)
{
    Move::_yFrom = yFrom;
}

int Move::getYTo () const
{
    return _yTo;
}

void Move::setYTo (int yTo)
{
    Move::_yTo = yTo;
}

Move::Move (int xFrom, int yFrom, int xTo, int yTo)
{
    this->_xFrom = xFrom;
    this->_xTo = xTo;
    this->_yFrom = yFrom;
    this->_yTo = yTo;
}

void Move::execute ()
{
    this->pieceToMove = Board::pieceOnSquare(this->getXFrom(), this->getYFrom());
    this->pieceToCapture = Board::pieceOnSquare(this->getXTo(), this->getYTo());
    this->pieceToMove->move(this->getXTo(), this->getYTo());
}

void Move::undo ()
{
    this->pieceToMove->move(this->getXFrom(), this->getYFrom());
    Board::addPiece(pieceToCapture);
}

Move *Move::getMovePointerFromMove () const
{
    return new Move(this->getXFrom(), this->getYFrom(), this->getXTo(), this->getYTo());
}
