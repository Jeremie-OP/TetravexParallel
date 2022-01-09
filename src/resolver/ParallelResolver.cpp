//
// Created by wiakx on 09/01/2022.
//

#include "ParallelResolver.h"

ParallelResolver::ParallelResolver() {
    start = chrono::high_resolution_clock::now();
}

bool ParallelResolver::solver(Game *game, int numberOfPlayedPiece, int newI) {
    if (game->getSize() * game->getSize() <= numberOfPlayedPiece) {
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;  //on affiche le temps
        game->showBoard();  //on affiche la board
        return true;    //on sort de la recursivité
    }
    int oldI;
    if(newI == 0) newI= game->getSize() * game->getSize() -1;
    for (int i = 0; i <= newI;) {
        if (game->placePiece(game->getPieces()[i])) {
            oldI = i;
            game->swapPieces(oldI, newI);
            if (!solver(game, numberOfPlayedPiece +1, newI)) {
                game->removePiece();
                game->swapPieces(oldI, newI);
                i++;
            } else return true;
        } else i++;
    }
    return false;
}


