//
// Created by Elias Aggergaard Larsen on 16/07/2024.
//

#include "TextureManager.h"

Texture2D TextureManager::wKing = LoadTexture("../Resources/WKing");
Texture2D TextureManager::bKing = LoadTexture("../Resources/BKing");
Texture2D TextureManager::wQueen = LoadTexture("../Resources/WQueen");
Texture2D TextureManager::bQueen = LoadTexture("../Resources/BQueen");
Texture2D TextureManager::wBishop = LoadTexture("../Resources/WBishop");
Texture2D TextureManager::bBishop = LoadTexture("../Resources/BBishop");
Texture2D TextureManager::wKnight = LoadTexture("../Resources/WKnight");
Texture2D TextureManager::bKnight = LoadTexture("../Resources/BKnight");
Texture2D TextureManager::wRook = LoadTexture("../Resources/WRook");
Texture2D TextureManager::bRook = LoadTexture("../Resources/BRook");
Texture2D TextureManager::wPawn = LoadTexture("../Resources/WPawn");
Texture2D TextureManager::bPawn = LoadTexture("../Resources/BPawn");

void TextureManager::loadTextures ()
{
    wKing = LoadTexture("../Resources/ChessPieces/WKing.png");
    bKing = LoadTexture("../Resources/ChessPieces/BKing.png");
    wQueen = LoadTexture("../Resources/ChessPieces/WQueen.png");
    bQueen = LoadTexture("../Resources/ChessPieces/BQueen.png");
    wBishop = LoadTexture("../Resources/ChessPieces/WBishop.png");
    bBishop = LoadTexture("../Resources/ChessPieces/BBishop.png");
    wKnight = LoadTexture("../Resources/ChessPieces/WKnight.png");
    bKnight = LoadTexture("../Resources/ChessPieces/BKnight.png");
    wRook = LoadTexture("../Resources/ChessPieces/WRook.png");
    bRook = LoadTexture("../Resources/ChessPieces/BRook.png");
    wPawn = LoadTexture("../Resources/ChessPieces/WPawn.png");
    bPawn = LoadTexture("../Resources/ChessPieces/BPawn.png");
}
