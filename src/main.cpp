//
// Created by wiakx on 09/01/2022.
//

#include <iostream>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"
#include "resolver/ThreadPool.h"
#include "resolver/ParallelResolver.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game game = ImportGame().readFile("../../test/8x8.txt");
//    SequentialResolver* solver = new SequentialResolver(game);
//    solver->resolveP(&game,0,0);
    ThreadPool* threadPool = new ThreadPool();
    threadPool->initializeSolverShuffle(game);
//    ParallelResolver solver(game);
//    solver.initializerSolver(0);
    return 0;
}