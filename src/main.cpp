#include <iostream>
#include "test/ImportGame.h"

using namespace std;

int main() {
    cout << "Bienvenu dans le programme de Tetravex" << endl;
    Game* game = ImportGame().readFile("../../test/5x5.txt");

    return 0;
}