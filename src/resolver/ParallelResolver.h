//
// Created by wiakx on 09/01/2022.
//

#ifndef TETRAVEX_PARALLELRESOLVER_H
#define TETRAVEX_PARALLELRESOLVER_H


#include <chrono>
#include "../game/Game.h"
#include "iostream"

class ParallelResolver {
public:
    ParallelResolver();
    void initializerSolver();
    bool solver(Game *game, int numberOfPlayedPiece, int newI);
    chrono::high_resolution_clock::time_point start;
};


#endif //TETRAVEX_PARALLELRESOLVER_H
