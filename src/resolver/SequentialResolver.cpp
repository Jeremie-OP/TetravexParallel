//
// Created by wiakx on 07/01/2022.
//

#include "SequentialResolver.h"



SequentialResolver::SequentialResolver(Game _game) {
    game = &_game;
    pieceNotPlayed = game->getPieces();
    currentIndex = 0;
    this->resolve(&pieceNotPlayed);
}

bool SequentialResolver::resolve(vector<Piece*>* listPieces) {
    if (pieceNotPlayed.empty()) {
        cout << "J'ai ! " << endl;
        game->showBoard();
        return true;
    }
    for (int i = 0; i < pieceNotPlayed.size(); i++) {
        if (game->placePiece(pieceNotPlayed[i])) {
            piecePlayed.push_back(pieceNotPlayed[i]);
            pieceNotPlayed.erase(pieceNotPlayed.begin() + i);
//            i--;
            if (!resolve(listPieces)) {
                game->removePiece();
                pieceNotPlayed.insert(pieceNotPlayed.begin() + i,piecePlayed.back());
                piecePlayed.pop_back();
            } else return true;
        }
    }
    return false;
}


