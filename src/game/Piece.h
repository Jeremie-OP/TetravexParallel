#ifndef TETRAVEX_PIECE_H
#define TETRAVEX_PIECE_H

using namespace std;

class Piece
{
private:
    bool placed;
    int top, bot, left, right;
    /* data */
public:
    Piece(int _left, int _top, int _right, int _bot);
    void placePiece() { placed = true;}
    void removePiece() { placed = false;}
    bool isPlaced(){ return placed; }

    int getLeft() { return left; }
    int getRight() { return right; }
    int getTop() { return top; }
    int getBot() { return bot; }

};

#endif //TETRAVEX_PIECE_H