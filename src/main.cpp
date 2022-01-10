//
// Created by wiakx on 09/01/2022.
//

#include <iostream>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"
#include "resolver/ThreadPool.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    cout << "Chargement du fichier: " << argv[1] << endl;
    Game game = ImportGame().readFile(argv[1]);
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