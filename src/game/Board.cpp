#include "Board.h"

//  logique de la table de jeu:
//  1 | 2 | 3
//  4 | 5 | 6
//  7 | 8 | 9
// 

Board::Board(int size) {
    this->size = size;
}

bool Board::placePiece(Piece piece) {
    int index = board.size();
    int row = index / size;
    if (row == 0) {                         // si la piece à placer se trouver sur la premiere ligne

    } else if (row == size - 1) {           //si la piece se trouve sur la dernier ligne

    } else {                                  //si la piece se trouve sur une autre ligne
        if (board[index - size].getBot() != piece.getTop()) return false;
    }

    int column = index - size * row;
    if (column == 0) {                      //si la piece se trouve sur la premiere colonne

    } else if (column == size - 1) {         //si la piece se trouve sur la derniere colonne

    } else {                                //si la piece se trouve sur une autre colonne
        if (board[index - 1].getRight() != piece.getLeft()) return false;
    }
    board[index] = piece;
    return true;
}