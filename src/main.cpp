//
// Created by wiakx on 09/01/2022.
//

#include <iostream>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"
#include "resolver/ThreadPool.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game game = ImportGame().readFile("../../test/7x7.txt");
    cout << "Sequentiel:" << endl;
    SequentialResolver* solver = new SequentialResolver(game);        //Sequential
    solver->resolve(0,0);
    ThreadPool* threadPool = new ThreadPool();                          //Parallel
    cout << endl <<"Parellele shuffle :" << endl;
    threadPool->initializeSolverShuffle(game);
    cout << endl <<"Parellele distribué :" << endl;
    threadPool->initializeSolver(game);
    return 0;
}