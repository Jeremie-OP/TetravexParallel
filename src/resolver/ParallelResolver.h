//
// Created by wiakx on 09/01/2022.
//

#ifndef TETRAVEX_PARALLELRESOLVER_H
#define TETRAVEX_PARALLELRESOLVER_H


#include <chrono>
#include "../game/Game.h"
#include "iostream"
#include "atomic"

class ParallelResolver {
private:
    int size;
    Game game;
    atomic<bool>* atom;
    int loop;
public:
    ParallelResolver(Game game, atomic<bool>* atom);
    void initializerSolver();
    bool solver(vector<Piece*> &listPiece , int numberOfPlayedPiece, int newI);
    chrono::high_resolution_clock::time_point start;

    void launch(Game game, vector<Piece *> &listPiece, int i);

    void initializerSolverShuffled();

    bool solverShuffled(vector<Piece *> &listPiece, int numberOfPlayedPiece, int newI);
};


#endif //TETRAVEX_PARALLELRESOLVER_H
