//
// Created by wiakx on 09/01/2022.
//
#include "thread"
#include "vector"
#include "SequentialResolver.h"

#ifndef TETRAVEX_THREADPOOL_H
#define TETRAVEX_THREADPOOL_H

using namespace std;

class ThreadPool {
private:
    vector<thread*> threadPool;
    int numOfThreads;
public:
    ThreadPool();
    void addThreadPool(thread* t);
    void joinThreads();
    void killThreads();

    void initializeSolver(Game game);
};


#endif //TETRAVEX_THREADPOOL_H
