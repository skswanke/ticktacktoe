// Sam Swanke

#ifndef game_hpp
#define game_hpp
#include "board.hpp"
#include "gameService.hpp"
#include "fileService.hpp"
#include <string>

class Game {
public:
    // Only default constructor for new game
    Game();
    // Starts the game.
    // R: n/a, M: n/a, E: n/a
    void start();
    // Takes a turn.
    // R: string containing whose turn it is, M: n/a, E: n/a
    void turn(int x, int y, bool player);
    // Checks if the game is won or lost.
    // R: n/a, M: n/a, E: n/a
    int isOver();
    // Displays end logic.
    // R: n/a, M: n/a, E: n/a
    void end(int i);
    Board board;
    GameService gameService;
    FileService fileService;
};

#endif