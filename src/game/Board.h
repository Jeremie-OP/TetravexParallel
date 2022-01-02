#include <vector>
#include "Element.h"

using namespace std;

class Board{
private:
    int size;
    vector<vector <Element*>> board;
public:
    Board();
    ~Board();
};
