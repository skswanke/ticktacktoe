// Sam Swanke

#ifndef abstractBoard_hpp
#define abstractBoard_hpp
#include <string>
using namespace std;

class AbstractBoard {
public:
    // Only default constructor to make an empty board
    AbstractBoard();
    // Provides method to change board
    // R: position to move as x,y choord, and player. M: board. E: board.
    virtual void move();
    // Provides method to set board based on existing state
    // R: nothing, M: board state, E: resets board to new state
    virtual void set();
};

#endif
