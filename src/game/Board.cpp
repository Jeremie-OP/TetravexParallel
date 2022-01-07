#include "Board.h"

//  logique de la table de jeu:
//  1 | 2 | 3
//  4 | 5 | 6
//  7 | 8 | 9
// 

Board::Board(int size) {
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        board.push_back(NULL);
    }
    
}

bool Board::placePiece(int index, Piece piece) {
}