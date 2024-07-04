//
// Created by Elias Aggergaard Larsen on 03/07/2024.
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
    bool black = false;
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
            if (piece->getX() == pieceOnHand->getX() && piece->getY() == pieceOnHand->getY())
            {
                DrawTexture(piece->getTexture(), GetMouseX(), GetMouseY(), WHITE);
            }
        }
        Texture2D texture = piece->getTexture();
        DrawTexture(texture, piece->getY() * tileSize, piece->getX() * tileSize, WHITE);
    }
    EndDrawing();
}

void UI::onClick (Vector2 position)
{
    if (pieceOnHand != nullptr)
    { return; }
    int xToGet = (int) position.x / tileSize;
    int yToGet = (int) position.y / tileSize;
    this->pieceOnHand = Board::pieceOnSquare(yToGet, xToGet);
}

void UI::onRelease (Vector2 position)
{
    int xToGet = (int) position.x;
    int yToGet = (int) position.y;
    if (pieceOnHand != nullptr)
    {
        if (pieceOnHand->isMoveLegal(xToGet, yToGet))
        {
            pieceOnHand->move(xToGet, yToGet);
        }
    }
    pieceOnHand = nullptr;
}
