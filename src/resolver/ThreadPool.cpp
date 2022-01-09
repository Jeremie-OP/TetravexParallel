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
    vector<SequentialResolver> tabOfSolver;
    for (int i=0 ; i < numOfThreads; i++) {
        tabOfSolver.emplace_back(SequentialResolver(game.gameCopy()));
        addThreadPool(new thread(&SequentialResolver::resolve,tabOfSolver.back(), i, 0));
    }
    joinThreads();

}


