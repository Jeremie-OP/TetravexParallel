//
// Created by wiakx on 09/01/2022.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool() {
    numOfThreads = thread::hardware_concurrency();
}

void ThreadPool::addThreadPool(thread* t) {
    threadPool.push_back(t);
}

void ThreadPool::joinThreads() {
    for (thread* t : threadPool) {
        t->join();
    }
}

void ThreadPool::initializeSolver(Game game) {
    vector<ParallelResolver> tabOfSolver;
    atom = new atomic<bool>();
    atom = false;
    int size = game.getSize();
    size *= size;
    int i = 0;
    for (;i < numOfThreads; i++) {
        Game* gameTmp = new Game(game.gameCopy());
        game.swapPieces(0,i);
        tabOfSolver.emplace_back(ParallelResolver(*gameTmp, &atom));
        addThreadPool(new thread(&ParallelResolver::initializerSolver,tabOfSolver.back()));
    }
    while (!atom) {
        for (thread* t : threadPool) {
            if (t->joinable()){
                t->join();
                Game* gameTmp = new Game(game.gameCopy());
                game.swapPieces(0,i);
                tabOfSolver.emplace_back(ParallelResolver(*gameTmp, &atom));
                t = new thread(&ParallelResolver::initializerSolver,tabOfSolver.back());
                i++;
            }
        }
    }

}

void ThreadPool::initializeSolverShuffle(Game game) {
    vector<ParallelResolver> tabOfSolver;
    atom = new atomic<bool>();
    atom = false;
    int size = game.getSize();
    size *= size;
    int i = 0;
    for (;i < numOfThreads; i++) {
        Game* gameTmp = new Game(game.gameCopy());
        gameTmp->shufflePieces();
        tabOfSolver.emplace_back(ParallelResolver(*gameTmp, &atom));
        addThreadPool(new thread(&ParallelResolver::initializerSolverShuffled,tabOfSolver.back()));
    }
    joinThreads();

}

