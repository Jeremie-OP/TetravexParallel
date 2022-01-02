
using namespace std;

class Element
{
private:
    bool placed;
    int top, bot, left, right;
    /* data */
public:
    Element(int _top, int _bot, int _left, int _right);
    ~Element();
    void setPlaced(bool _placed);
    bool isPlaced();

};
