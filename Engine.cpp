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
