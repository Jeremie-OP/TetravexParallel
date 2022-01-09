//
// Created by wiakx on 07/01/2022.
//
#include "vector"
#include <iostream>
#include <chrono>
#include "../game/Game.h"

#ifndef TETRAVEX_SEQUENTIALRESOLVER_H
#define TETRAVEX_SEQUENTIALRESOLVER_H


class SequentialResolver {
    private:
        vector<Piece*> piecePlayed, pieceNotPlayed;
        Game* game;
        int size;
        chrono::high_resolution_clock::time_point start;
    public:
        SequentialResolver(Game _game);
        bool resolve(int numberOfPlayedPiece, int newI);
        bool resolveP(Game* game, int numberOfPlayedPiece, int newI);
};


#endif //TETRAVEX_SEQUENTIALRESOLVER_H
