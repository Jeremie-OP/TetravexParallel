#include "Board.h"

#ifndef TETRAVEX_GAME_H
#define TETRAVEX_GAME_H


using namespace std;

class Game
{
private:
    Board* board;
    int size;
    vector<Piece> listePiece;
public:
    Game(int _size);
    int getSize() {return size;}
    void addPiece(Piece piece) { listePiece.push_back(piece);}
    bool placePiece(Piece piece);

    vector<Piece> getPieces();
};

#endif TETRAVEX_GAME_H