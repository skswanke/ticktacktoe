// Sam Swanke

#ifndef gameService_hpp
#define gameService_hpp
#include <string>

class GameService {
public:
    // Only default constructor for new game
    GameService();
    // Checks if the game is won or lost.
    // R: n/a, M: n/a, E: n/a
    int isOver(string s);
    // Displays end logic.
    // R: n/a, M: n/a, E: n/a
    void end(int i);
};

#endif
