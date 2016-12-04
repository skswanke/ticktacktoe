// Sam Swanke

#include "game.hpp"
#include <iostream>
using namespace std;
/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */
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

#include "graphicService.hpp"
#include <cmath>

GLdouble width, height;
int wd;

bool followActive;

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void drawCircle(int x, int y, int radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(x, y);
    for (int i = 0; i < 360; ++i) {
        glVertex2f(x + cosf(i) * radius, y + sinf(i) * radius);
    }
    glEnd();
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
    
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 0.8f);
    glVertex2f(100.0f, 100.0f);
    glVertex2f(200.0f, 200.0f);
    glVertex2f(300.0f, 200.0f);
    glVertex2f(400.0f, 100.0f);
    glEnd();
    
    glColor4f(0.360f, 0.360f, 0.360f, 0.5f);

    drawCircle(200, 200, 50);
    
    glBegin(GL_QUADS);
    
    glEnd();
    
    string message = "Save";
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2i(210, 450);
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
    // space
    if (key == 32) {
    }
    glutPostRedisplay();
    
    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }
    
    glutPostRedisplay();
    
    return;
}

void cursor(int x, int y) {
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    if (state == GLUT_UP) {
        followActive = !followActive;
    }
    
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
    wd = glutCreateWindow("Fun with Drawing!" /* title */ );
    
    
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

    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}