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

Game Game::gameCopy() {
    Game gameCopy(this->getSize());
    for (Piece* p : this->listePiece) {
        gameCopy.addPiece(new Piece(p->getLeft(), p->getTop(), p->getRight(), p->getBot()));
    }
    return gameCopy;
}

void Game::swapPieces(int x, int y) {
    swap(listePiece[x], listePiece[y]);
}

