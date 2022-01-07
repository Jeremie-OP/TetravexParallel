
add_executable(tetravex
        main.cpp
        game/Game.h game/Game.cpp
        game/Board.h game/Board.cpp
        game/Piece.h game/Piece.cpp
        test/ImportGame.h test/ImportGame.cpp
        resolver/SequentialResolver.cpp resolver/SequentialResolver.h)