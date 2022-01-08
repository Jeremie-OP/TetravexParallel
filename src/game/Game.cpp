#include "Game.h"

Game::Game(int _size) {
    size = _size;
    board = new Board(size);
}

bool Game::placePiece(Piece* piece) {
    return board->placePiece(piece);
}

bool Game::gameDone() {
    for (Piece* p : listePiece) {
        if (!p->isPlaced()) return false;
    }
    return true;
}

void Game::removePiece() {
    board->enleverPiece();
}

