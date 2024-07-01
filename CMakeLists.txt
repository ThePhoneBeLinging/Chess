cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 26)

add_executable(Chess main.cpp
        Pieces/Piece.h
        Pieces/Piece.cpp
        Board.h
        Board.cpp
        Pieces/King.h
        Pieces/King.cpp
        Pieces/Knight.h
        Pieces/Knight.cpp
        Pieces/Rook.h
        Pieces/Rook.cpp
        Pieces/Pawn.h
        Pieces/Pawn.cpp
        Pieces/Bishop.h
        Pieces/Bishop.cpp
        Pieces/Queen.h
        Pieces/Queen.cpp)
