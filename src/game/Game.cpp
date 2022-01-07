#include "Game.h"

Game::Game(int _size) {
    size = _size;
    board = new Board(size);
}

