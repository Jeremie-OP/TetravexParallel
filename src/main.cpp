#include <iostream>
#include <chrono>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game game = ImportGame().readFile("../../test/7x7.txt");
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    SequentialResolver* solver = new SequentialResolver(game);
    cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;
    //solver->resolve();
    return 0;
}