cmake_minimum_required(VERSION 3.28)
project(Chess)

set(CMAKE_CXX_STANDARD 26)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()
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
        Pieces/Queen.cpp
        UI.h
        UI.cpp
        Move.cpp
        Move.h
        Engines/V1Engine.cpp
        Engines/V1Engine.h
        EngineTester.h
        EngineTester.cpp
        TextureManager.h
        TextureManager.cpp
        Engines/V2Engine.h
        Engines/V2Engine.cpp
        Engines/V3Engine.h
        Engines/V3Engine.cpp
)
target_link_libraries(${PROJECT_NAME} raylib)