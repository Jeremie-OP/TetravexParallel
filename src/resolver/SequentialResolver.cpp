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
}

bool SequentialResolver::resolveP(Game &game, int numberOfPlayedPiece, int newI) {
    if (numberOfPlayedPiece >= size) {  //si le nombre de piece joué correpond au nombre de piece à placer alors c'est qu'on a la solution
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;  //on affiche le temps
        game.showBoard();  //on affiche la board
        return true;    //on sort de la recursivité
    }
    int oldI;
    if (newI == 0) newI = game.getPieces().size() - 1;
    for (int i = 0; i <= newI; ) {
        if (game.placePiece(pieceNotPlayed[i])) {
            oldI = i;
            swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);            //si la piece est utilisé on la swap avec la derniere piece non swap de fond du vecteur
            if (!resolve(numberOfPlayedPiece + 1, newI -1)) {
                game.removePiece();                                           //la piece n'est pas la bonne, on l'enleve de la board
                swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);        //on remet la piece à son emplacement d'origine dans le vecteur
                i++;
            } else return true;     //c'est tout bon, on sort de la recursivité
        } else i++;
    }
    return false;
}


bool SequentialResolver::resolve(int numberOfPlayedPiece, int newI) {

    if (numberOfPlayedPiece >= size) {  //si le nombre de piece joué correpond au nombre de piece à placer alors c'est qu'on a la solution
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;  //on affiche le temps
        game->showBoard();  //on affiche la board
        return true;    //on sort de la recursivité
    }
    int oldI;
    if (newI == 0) newI = game->getPieces().size() - 1;
    for (int i = 0; i <= newI; ) {
        if (game->placePiece(pieceNotPlayed[i])) {
            oldI = i;
            swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);            //si la piece est utilisé on la swap avec la derniere piece non swap de fond du vecteur
            if (!resolve(numberOfPlayedPiece + 1, newI -1)) {
                game->removePiece();                                           //la piece n'est pas la bonne, on l'enleve de la board
                swap(pieceNotPlayed[oldI],pieceNotPlayed[newI]);        //on remet la piece à son emplacement d'origine dans le vecteur
                i++;
            } else return true;     //c'est tout bon, on sort de la recursivité
        } else i++;
    }
    return false;
}


