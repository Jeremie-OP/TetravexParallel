#include <iostream>
#include "test/ImportGame.h"
#include "resolver/SequentialResolver.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game game = ImportGame().readFile("../../test/7x7.txt");
    SequentialResolver* solver = new SequentialResolver(game);
    solver->resolve(0,0);
    return 0;
}