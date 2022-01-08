//
// Created by wiakx on 07/01/2022.
//
#include "vector"
#include <iostream>
#include "../game/Game.h"

#ifndef TETRAVEX_SEQUENTIALRESOLVER_H
#define TETRAVEX_SEQUENTIALRESOLVER_H


class SequentialResolver {
    private:
        vector<Piece*> piecePlayed, pieceNotPlayed;
        Game* game;
        int currentIndex;
    public:
        SequentialResolver(Game _game);
        bool resolve(vector<Piece*>* listePieces);
};


#endif //TETRAVEX_SEQUENTIALRESOLVER_H
