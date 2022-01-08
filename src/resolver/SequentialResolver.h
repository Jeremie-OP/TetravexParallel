//
// Created by wiakx on 07/01/2022.
//
#include "vector"
#include "../game/Game.h"

#ifndef TETRAVEX_SEQUENTIALRESOLVER_H
#define TETRAVEX_SEQUENTIALRESOLVER_H


class SequentialResolver {
    private:
        vector<Piece> pieceToPlay, piecePlayed, pieceNotPlayed;
    public:
        Game resolve(Game game);
        bool solver(Game* game);
};


#endif //TETRAVEX_SEQUENTIALRESOLVER_H
