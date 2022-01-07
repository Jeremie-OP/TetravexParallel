
using namespace std;

class Piece
{
private:
    bool placed;
    int top, bot, left, right;
    /* data */
public:
    Piece(int _top, int _bot, int _left, int _right);
    void setPlaced();
    bool isPlaced();

};
