#include "Piece.h"

Piece::Piece(int _left, int _top, int _right, int _bot) {
    left = _left;
    top = _top;
    right = _right;
    bot = _bot;
    placed = false;
}

bool Piece::isPlaced() {
    return this->placed;
}

void Piece::setPlaced() {
    (placed) ? placed = false : placed = true;
}