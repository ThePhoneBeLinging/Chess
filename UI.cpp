//
// Created bx Elias Aggergaard Larsen on 03/07/2024.
//

#include "UI.h"

int UI::tileSize = 75;

UI::UI ()
{
    this->pieceOnHand = nullptr;
}

void UI::draw ()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        this->onClick(GetMousePosition());
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        this->onRelease(GetMousePosition());
    }
    ClearBackground(BLACK);
    BeginDrawing();
    Color color = BLACK;
    for (int i = 1; i < 9; i ++)
    {
        for (int k = 1; k < 9; k ++)
        {
            if ((i + k) % 2 == 0)
            {
                color = DARKBROWN;
            }
            else
            {
                color = LIGHTGRAY;
            }
            DrawRectangle(k * tileSize, i * tileSize, tileSize, tileSize, color);
        }
    }

    for (std::shared_ptr<Piece> piece: Board::getPieces())
    {
        if (pieceOnHand != nullptr)
        {
            if (piece->getY() == pieceOnHand->getY() && piece->getX() == pieceOnHand->getX())
            {
                DrawTexture(piece->getTexture(), GetMouseX(), GetMouseY(), WHITE);
                continue;
            }
        }
        Texture2D teyture = piece->getTexture();
        DrawTexture(teyture, piece->getX() * tileSize, piece->getY() * tileSize, WHITE);
    }
    EndDrawing();
}

void UI::onClick (Vector2 position)
{
    int xToGet = (int) position.x / tileSize;
    int yToGet = (int) position.y / tileSize;
    this->pieceOnHand = Board::pieceOnSquare(xToGet, yToGet);

}

void UI::onRelease (Vector2 position)
{
    int xToGet = (int) position.x / tileSize;
    int yToGet = (int) position.y / tileSize;
    if (pieceOnHand != nullptr)
    {
        Move move = Move(pieceOnHand->getX(), pieceOnHand->getY(), xToGet, yToGet);
        for (Move legalMove: Board::getAllLegalMoves())
        {
            if (move.equals(legalMove))
            {
                move.execute();
                break;
            }
        }
    }
    pieceOnHand = nullptr;
}

void UI::drawForEngineTester (std::string engine1, std::string engine2, int winsEngine1, int winsEngine2, int draws)
{
    UI::draw();
    DrawText(TextFormat("%s: %d", engine1.c_str(), winsEngine1), 800, 200, 40, WHITE);
    DrawText(TextFormat("Draws: %d", draws), 800, 250, 40, WHITE);
    DrawText(TextFormat("%s: %d", engine2.c_str(), winsEngine2), 800, 300, 40, WHITE);
}
