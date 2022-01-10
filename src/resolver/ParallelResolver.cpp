//
// Created by wiakx on 09/01/2022.
//

#include "ParallelResolver.h"

ParallelResolver::ParallelResolver(Game game, atomic<bool> *atom) : game(game) {
    this->game = game.gameCopy();
    start = chrono::high_resolution_clock::now();
    size = game.getSize();
    this->atom = atom;
    size *= size;
    loop=0;
}

bool ParallelResolver::solver(vector<Piece*> &listPiece, int numberOfPlayedPiece, int newI) {
    if (*atom) return false;
    if (numberOfPlayedPiece == 1) loop++;
    if (size <= numberOfPlayedPiece) {
        *atom = true;
        //cout << loop << " boucles realisés" << endl;
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;  //on affiche le temps
        game.showBoard();  //on affiche la board
        return true;    //on sort de la recursivité
    }
    int oldI;
    if(newI == 0) newI= size - 1 ;
    for (int i = 0; i <= newI;) {
        if (*atom) return false;
        if (game.placePiece(listPiece[i])) {
            oldI = i;
            swap(listPiece[oldI],listPiece[newI]);
            if (!solver(listPiece, numberOfPlayedPiece +1, newI - 1)) {
                game.removePiece();
                swap(listPiece[oldI],listPiece[newI]);
                i++;
            } else return true;
        } else i++;
        if (numberOfPlayedPiece == 1 ) return false;
    }
    return false;
}

bool ParallelResolver::solverShuffled(vector<Piece*> &listPiece, int numberOfPlayedPiece, int newI) {
    if (*atom) return false;
    if (numberOfPlayedPiece == 1) loop++;
    if (size <= numberOfPlayedPiece) {
        *atom = true;
        //cout << loop << " boucles realisés" << endl;
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;  //on affiche le temps
        game.showBoard();  //on affiche la board
        return true;    //on sort de la recursivité
    }
    int oldI;
    if(newI == 0) newI= size - 1 ;
    for (int i = 0; i <= newI;) {
        if (*atom) return false;
        if (game.placePiece(listPiece[i])) {
            oldI = i;
            swap(listPiece[oldI],listPiece[newI]);
            if (!solverShuffled(listPiece, numberOfPlayedPiece +1, newI - 1)) {
                game.removePiece();
                swap(listPiece[oldI],listPiece[newI]);
                i++;
            } else return true;
        } else i++;
    }
    return false;
}

void ParallelResolver::initializerSolver() {
    vector<Piece *> list = game.getPieces();
    solver(list,0,0);
}

void ParallelResolver::initializerSolverShuffled() {
    vector<Piece *> list = game.getPieces();
    solverShuffled(list,0,0);
}

