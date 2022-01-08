#include <string>
#include <iostream>
#include "Board.h"

//  logique de la table de jeu:
//  1 | 2 | 3
//  4 | 5 | 6
//  7 | 8 | 9
// 

Board::Board(int size) {
    this->size = size;
}

bool Board::placePiece(Piece* piece) {
    int index = board.size();
    int row = index / size;
    if (row == 0) {                         // si la piece à placer se trouver sur la premiere ligne

    } else {                                  //si la piece se trouve sur une autre ligne
        if (board[index - size]->getBot() != piece->getTop()) return false;
    }

    int column = index - size * row;
    if (column == 0) {                      //si la piece se trouve sur la premiere colonne

    } else {                                //si la piece se trouve sur une autre colonne
        if (board[index - 1]->getRight() != piece->getLeft()) return false;
    }
    piece->placePiece();
    board.push_back(piece);
    return true;
}

void Board::enleverPiece() {
    board.back()->removePiece();
    board.pop_back();
}


void Board::show() {
    int row;
    string line[3];
    cout << string(size* 4 + 2, '-') << endl;
    for (int i =0; i < size; i++) {
        row = i * size;
        line[0] = line[1] = line [2] = "|";
        for (int j = 0; j < size; ++j) {
            line[0]+= " " + to_string(board[j + row]->getTop()) + " |";
            line[1]+= to_string(board[j + row]->getLeft()) + " " + to_string(board[j+row]->getRight())+ "|";
            line[2]+= " " + to_string(board[j + row]->getBot()) + " |";
        }
        cout << line[0] << endl<< line[1] << endl<< line[2] << endl << string(size* 4 + 2, '-') << endl;
    }
}