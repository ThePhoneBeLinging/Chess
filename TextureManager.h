//
// Created by Elias Aggergaard Larsen on 16/07/2024.
//

#ifndef CHESS_TEXTUREMANAGER_H
#define CHESS_TEXTUREMANAGER_H


#include "raylib.h"

class TextureManager
{
public:
    static Texture2D wKing;
    static Texture2D bKing;
    static Texture2D wQueen;
    static Texture2D bQueen;
    static Texture2D wBishop;
    static Texture2D bBishop;
    static Texture2D wKnight;
    static Texture2D bKnight;
    static Texture2D wRook;
    static Texture2D bRook;
    static Texture2D wPawn;
    static Texture2D bPawn;

    static void loadTextures ();
};


#endif //CHESS_TEXTUREMANAGER_H
