//
// Created by wiakx on 07/01/2022.
//

#include "SequentialResolver.h"

Game SequentialResolver::resolve(Game game) {
    pieceToPlay = game.getPieces();
}

bool SequentialResolver::solver(Game* game) {
    pieceNotPlayed = pieceToPlay;
    for (auto &&p : pieceToPlay) {
        if (game->placePiece(p)) {

        }
    }

    return false;

}
