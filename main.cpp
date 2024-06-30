#include <iostream>
#include "Pieces/Piece.h"
#include "Pieces/Rook.h"

int main ()
{
    auto *piece = new Rook(3, 4, true);
    piece->isMoveLegal(3, 10);
    std::cout << piece->getX() << "," << piece->getY() << std::endl;
    return 0;
}
