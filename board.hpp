// Sam Swanke

#ifndef board_hpp
#define board_hpp
#include <string>
using namespace std;

class Board {
public:
    // Only default constructor to make an empty board
    Board();
    // Places and "x" or "o" on the board
    // R: position to move as x,y choord, and player. M: board. E: board.
    void move(int x, int y, string s);
    // Returns board state as a string of integers "100120022"
    // where 100 is top row 120 is mid and 022 is bottom
    // R: nothing, M: nothing, E: nothing
    string getState();
    friend std::ostream& operator << (std::ostream& outs, Board b);
private:
    string intToString(int i);
    void print(ostream &outs);
    int board[9];
};

#endif