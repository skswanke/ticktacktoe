// Sam Swanke

#include "game.hpp"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>

GLdouble width, height;
int lastX, lastY;
int wd;

Game game;

bool currPlayer = true;

void init() {
    width = 600;
    height = 600;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Red and opaque
}

void drawBoard(){    
    float topThird = height - height/3;
    float botThird = height/3;
    float lefThird = width/3;
    float rigThird = width - width/3;
    float widthf = width;
    float heightf = height;

    // Top bar
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, topThird-5);
    glVertex2f(0.0f, topThird+5);
    glVertex2f(width, topThird+5);
    glVertex2f(width, topThird-5);
    glEnd();

    // Bot bar
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, botThird-5);
    glVertex2f(0.0f, botThird+5);
    glVertex2f(width, botThird+5);
    glVertex2f(width, botThird-5);
    glEnd();

    // Left bar
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(lefThird-5, 0.0f);
    glVertex2f(lefThird-5, heightf);
    glVertex2f(lefThird+5, heightf);
    glVertex2f(lefThird+5, 0.0f);
    glEnd();

    // Right bar
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(rigThird-5, 0.0f);
    glVertex2f(rigThird-5, heightf);
    glVertex2f(rigThird+5, heightf);
    glVertex2f(rigThird+5, 0.0f);
    glEnd();
}

int getRealCoord(int x){
    x = (x*200)+100;
    return x;
}

void drawO(int x, int y) {
    int realX = getRealCoord(x);
    int realY = getRealCoord(y);
    int radius = 50;

    glColor4f(0.360f, 0.360f, 0.360f, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(realX, realY);
    for (int i = 0; i < 360; ++i) {
        glVertex2f(realX + cosf(i) * radius, realY + sinf(i) * radius);
    }
    glEnd();
}

void drawX(int x, int y){
    int realX = getRealCoord(x);
    int realY = getRealCoord(y);
    // realY = realY-30;
    realX = realX-100;
    glColor4f(0.360f, 0.360f, 0.360f, 0.5f);
    // / bar
    glBegin(GL_QUADS);
    glVertex2f(realX+30, realY-60);
    glVertex2f(realX+20, realY-50);
    glVertex2f(realX+155, realY+60);
    glVertex2f(realX+165, realY+50);
    glEnd();
    // \ bar
    glBegin(GL_QUADS);
    glVertex2f(realX+155, realY-60);
    glVertex2f(realX+165, realY-50);
    glVertex2f(realX+30, realY+60);
    glVertex2f(realX+20, realY+50);
    glEnd();
}

void setXYfromInt(int i,int &x, int &y){
    x = i%3;
    y = i/3;
}

void drawState(){
    string state = game.board.getState();
    int i;
    int x;
    int y;
    for(i=0;i<9;i++){
        if(state[i] == 'x'){
            setXYfromInt(i,x,y);
            drawX(x,y);
        } else if (state[i] == 'o'){
            setXYfromInt(i,x,y);
            drawO(x,y);
        }
    }
}

void handleClick(int x, int y){
    int boardX = x/200;
    int boardY = y/200;
    if(game.board.isValid(boardX,boardY)){
        game.turn(boardX,boardY,currPlayer);
        lastX = boardX;
        lastY = boardY;
        currPlayer = !currPlayer;
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f);
    

    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    if(!game.gameService.isOver(game.board.getState())){
        drawBoard();
        drawState();
    } else {
        int i = game.gameService.isOver(game.board.getState());
        string endMessage = "O's Win! Congratulations!";
        if(i == 1){
            endMessage = "X's Win! Congratulations!";
        }
        if(i == 3){
            endMessage = "   It's a tie! Good effort!";
        }
        glColor3f(0.0f, 1.0f, 0.0f);
        glRasterPos2i(width/2-130, height/2-5);
        for (int c = 0; c < endMessage.length(); ++c) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, endMessage[c]);
        }
    }
    string message;
    if(currPlayer){
        message = "s: Save, esc: Exit, l: Load, turn: X";
    } else {
        message = "s: Save, esc: Exit, l: Load, turn: O";
    }
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2i(width/2-150, height - 20);
    if(game.gameService.isOver(game.board.getState())){
        message = "r: Restart, esc: Exit";
        glRasterPos2i(200, height/2-30);
    }
    for (int c = 0; c < message.length(); ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,
                            message[c]);
    }
    
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    // r
    if (key == 114 && game.gameService.isOver(game.board.getState())) {
        game.board.set("000000000");
    }
    // s
    if (key == 115) {
        game.fileService.save(game.board.getState());
    }
    // l
    if (key == 108) {
        game.board.set(game.fileService.load());
    }
    // backspace
    if (key == 8) {
        game.board.undo(lastX, lastY);
        currPlayer = !currPlayer;
    }

    glutPostRedisplay();
    return;
}

void kbdS(int key, int x, int y) {
    glutPostRedisplay();
    return;
}

void cursor(int x, int y) {
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        handleClick(x,y);
    }
    // Needs right click to call undo() on board
    
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 500); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Tic Tac Toe!" /* title */ );
    
    
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);

    // Game g;
    // g.start();

    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}