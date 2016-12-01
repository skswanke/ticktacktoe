// Sam Swanke

#ifndef fileService_hpp
#define fileService_hpp
#include <string>
#include <iostream>

class FileService {
public:
    // Only default constructor for new game
    FileService();
    // Starts the game.
    // R: n/a, M: n/a, E: n/a
    void save(string s);
    string load();
};

#endif
