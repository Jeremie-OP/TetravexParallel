#include "Game.h"

Game::Game(int _size) {
    size = _size;
    board = new Board(size);
}

bool Game::placePiece(Piece* piece) {
    return board->placePiece(piece);
}

void Game::removePiece() {
    board->enleverPiece();
}

