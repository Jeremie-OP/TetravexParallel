#include "Board.h"

#ifndef TETRAVEX_GAME_H
#define TETRAVEX_GAME_H


using namespace std;

class Game
{
private:
    Board* board;
    int size;
    vector<Piece*> listePiece;
public:
    explicit Game(int _size);
    int getSize() const {return size;}
    void addPiece(Piece* piece) { listePiece.push_back(piece);}
    bool placePiece(Piece* piece);
    void removePiece();

    void showBoard() { board->show();}

    Game gameCopy();

    vector<Piece*> getPieces() { return listePiece;};
    void swapPieces(int x, int y);
};

#endif //TETRAVEX_GAME_H