#include <fstream>
#include <iostream>
#include "ImportGame.h"


Game ImportGame::readFile(string file) {
    cout << "Chargement du fichier: " << file << endl;

    ifstream ifile(file);               // lecture du fichier contenant les données du jeu
    if (ifile) {
        int size;
        ifile >> size >> size;           // on recup la taille du jeu
        Game game = Game(size);
        int left, top, right, bot;
        int i = 0;
        while (ifile >> left >> top >> right >> bot) {   //on recup les valeurs d'une piece
            game.addPiece(new Piece(left, top, right, bot));       //on ajoute la piece au jeu
            i++;
        }
        cout << "Taille du tableau : " << size << "x" << size << " | nombre de piece chargées: " << i << endl;
        return game;
    } else {
        cout << "Le fichier n'a pas été trouvé." << endl;
        throw ("error");
    }

}
