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
        int size;
        int currentIndex;
    public:
        SequentialResolver(Game _game);
        bool resolve(vector<Piece*>* listePieces, int numberOfPlayedPiece, int newI);
};


#endif //TETRAVEX_SEQUENTIALRESOLVER_H
