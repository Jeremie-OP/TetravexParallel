//
// Created by wiakx on 07/01/2022.
//

#include "SequentialResolver.h"



SequentialResolver::SequentialResolver(Game _game) {
    game = &_game;
    size = game->getSize();
    size = size * size;
    pieceNotPlayed = game->getPieces();
    start = chrono::high_resolution_clock::now();
    this->resolve(&pieceNotPlayed,0,0);
}

bool SequentialResolver::resolve(vector<Piece*>* listPieces, int numberOfPlayedPiece, int newI) {
    if (numberOfPlayedPiece >= size) {
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;
        game->showBoard();
        return true;
    }
    int oldI;
    if (newI == 0) newI = pieceNotPlayed.size() - 1;
    for (int i = 0; i <= newI; ) {
        if (game->placePiece(pieceNotPlayed[i])) {
            oldI = i;
            swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);
            if (!resolve(listPieces, numberOfPlayedPiece + 1, newI -1)) {
                game->removePiece();
                swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);
                i++;
            } else return true;
        } else i++;
    }
    return false;
}


