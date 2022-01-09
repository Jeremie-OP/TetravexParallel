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
void ThreadPool::killThreads() {
    for(thread* t: threadPool) {
        t->~thread();
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
        vector<Piece *> list = game.getPieces();
        addThreadPool(new thread(&ParallelResolver::initializerSolver,tabOfSolver.back()));
    }
    while (!atom) {
        for (thread* t : threadPool) {
            if (t->joinable()){
                t->join();
                Game* gameTmp = new Game(game.gameCopy());
                game.swapPieces(0,i);
                tabOfSolver.emplace_back(ParallelResolver(*gameTmp, &atom));
                vector<Piece *> list = game.getPieces();
                t = new thread(&ParallelResolver::initializerSolver,tabOfSolver.back());
                i++;
            }
        }
    }
    killThreads();

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
        vector<Piece *> list = game.getPieces();
        addThreadPool(new thread(&ParallelResolver::initializerSolverShuffled,tabOfSolver.back()));
    }
    while (!atom) {
        for (thread* t : threadPool) {
            if (t->joinable()){
                t->join();
                Game* gameTmp = new Game(game.gameCopy());
                gameTmp->shufflePieces();
                tabOfSolver.emplace_back(ParallelResolver(*gameTmp, &atom));
                vector<Piece *> list = game.getPieces();
                t = new thread(&ParallelResolver::initializerSolverShuffled,tabOfSolver.back());
                i++;
            }
        }
    }
    killThreads();

}

