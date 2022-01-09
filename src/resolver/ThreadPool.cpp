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
    for (int i=0 ; i < numOfThreads; i++) {
        Game tmp = game.gameCopy();
        auto* solver = new SequentialResolver(tmp);
        addThreadPool(new thread(&SequentialResolver::resolveP,solver, tmp ,0, 0));
    }
    joinThreads();

}


