#include <vector>
#include "Piece.h"


using namespace std;

class Board{
private:
    int size;
    vector<Piece*> board;
public:
    Board(int size);
    ~Board();
    bool placePiece(int index, Piece piece);
};
