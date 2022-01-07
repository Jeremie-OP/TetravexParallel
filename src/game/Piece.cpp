#include "Piece.h"

Piece::Piece(int left, int top, int right, int bot) {
    this->left = left;
    this->top = top;
    this->right = right;
    this->bot = bot;
    this->placed = false;
}

bool Piece::isPlaced() {
    return this->placed;
}

void Piece::setPlaced() {
    (placed) ? placed = false : placed = true;
}