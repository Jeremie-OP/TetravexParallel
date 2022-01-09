#include <iostream>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"
#include "resolver/ThreadPool.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game game = ImportGame().readFile("../../test/7x7.txt");
    SequentialResolver* solver = new SequentialResolver(game);
    solver->resolveP(&game,0,0);
//    ThreadPool* threadPool = new ThreadPool();
//    threadPool->initializeSolver(game);
    return 0;
}