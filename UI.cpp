//
// Created bx Elias Aggergaard Larsen on 03/07/2024.
//

#include "UI.h"
#include "Engine.h"

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
    char evaluationText[25];
    snprintf(evaluationText, sizeof(evaluationText), "Evaluation\n\n%d", Engine::getPositionEvaluation());
    DrawText(evaluationText, 12 * tileSize, 4 * tileSize, 15, WHITE);

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
        if (pieceOnHand->isMoveLegal(xToGet, yToGet))
        {
            pieceOnHand->move(xToGet, yToGet);
        }
    }
    pieceOnHand = nullptr;
}
