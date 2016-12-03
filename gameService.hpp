// Sam Swanke

#ifndef gameService_hpp
#define gameService_hpp
#include <string>
using namespace std;

class GameService {
public:
    // Only default constructor for new game
    GameService();
    // Checks if the game is won or lost.
    // R: n/a, M: n/a, E: n/a
    int isOver(string s);
};

#endif
