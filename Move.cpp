//
// Created by Elias on 05/07/2024.
//

#include "Move.h"
#include "Board.h"
#include "UI.h"
#include "Pieces/Queen.h"

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
    this->pieceToMove = Board::pieceOnSquare(this->getXFrom(), this->getYFrom());
    this->pieceToMoveHadMoved = pieceToMove->isHasMoved();
    this->pieceToCapture = Board::pieceOnSquare(this->getXTo(), this->getYTo());
    this->rookInvolvedInCastle = nullptr;
    this->queenCreated = nullptr;
}

void Move::execute ()
{
    if (pieceToMove->getValue() == 0)
    {
        int deltaX = pieceToMove->getX() - this->getXTo();
        if (std::abs(deltaX) == 2)
        {
            bool kingSideCastle = false;
            if (deltaX < 0)
            {
                kingSideCastle = true;
            }
            if (kingSideCastle)
            {
                this->rookInvolvedInCastle = Board::pieceOnSquare(8, this->getYFrom());
                this->_rookFromX = 8;
                this->_rookToX = this->getXTo() - 1;
                rookInvolvedInCastle->move(this->_rookToX, pieceToMove->getY());
            }
            else
            {
                this->rookInvolvedInCastle = Board::pieceOnSquare(1, this->getYFrom());
                this->_rookFromX = 1;
                this->_rookToX = this->getXTo() + 1;
                this->rookInvolvedInCastle->move(this->_rookToX, pieceToMove->getY());
            }
            Board::whiteTurn = ! Board::whiteTurn;
        }
    }
    if (pieceToMove->getValue() == 1)
    {
        if (pieceToMove->isWhite() && this->_xTo == 8)
        {
            this->queenCreated = std::make_shared<Queen>(this->getXTo(), this->getYTo(), pieceToMove->isWhite());
            Board::removePiece(pieceToMove);
            Board::addPiece(queenCreated);
        }
    }
    this->pieceToMove->move(this->getXTo(), this->getYTo());
}

void Move::undo ()
{
    if (this->queenCreated != nullptr)
    {
        Board::removePiece(queenCreated);
        Board::addPiece(pieceToMove);
    }
    this->pieceToMove->move(this->getXFrom(), this->getYFrom());
    Board::addPiece(pieceToCapture);
    this->pieceToMove->setHasMoved(this->pieceToMoveHadMoved);
    if (this->rookInvolvedInCastle != nullptr)
    {
        rookInvolvedInCastle->move(this->_rookFromX, this->getYFrom());
        Board::whiteTurn = ! Board::whiteTurn;
    }
}

Move *Move::getMovePointerFromMove () const
{
    return new Move(this->getXFrom(), this->getYFrom(), this->getXTo(), this->getYTo());
}

bool Move::equals (Move move)
{
    return this->getXFrom() == move.getXFrom() && this->getYFrom() == move.getYFrom() &&
           this->getXTo() == move.getXTo() && this->getYTo() == move.getYTo();
}
