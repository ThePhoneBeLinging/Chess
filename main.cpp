#include <iostream>
#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Board.h"

int main ()
{
    Board::startGame();
    if (Board::pieceOnSquare(1, 1) == nullptr)
    {
        return 0;
    }
    std::cout << Board::pieceOnSquare(1, 1)->getX() << "," << Board::pieceOnSquare(1, 1)->getY() << std::endl;
    return 0;
}
