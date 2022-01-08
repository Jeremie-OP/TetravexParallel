#include <vector>
#include "Piece.h"

#ifndef TETRAVEX_BOARD_H
#define TETRAVEX_BOARD_H

using namespace std;

class Board{
private:
    int size;
    vector<Piece*> board;
public:
    Board(int size);
    ~Board();
    bool placePiece(Piece* piece);       //place une piece sur le prochain emplacement possible
    void enleverPiece();    //enleve la piece du dernier emplacement
    void show();
};

#endif //TETRAVEX_BOARD_H