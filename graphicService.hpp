// Sam Swanke

#ifndef graphicService_hpp
#define graphicService_hpp

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Graphics {
public:
    Graphics();
    void drawX(int x, int y);
    void drawY(int x, int y);
    void DrawEnd(int i);
};

#endif