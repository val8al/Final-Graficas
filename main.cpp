#include <GL/glut.h>
#include <cmath>
#include "draw.h"


// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f, ly=0.0f;
// XZ position of the camera
float x=-6.0f,z=-3.0f,y=1.0f;

void renderScene(void) {


    // Clear Color and Depth Buffers

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(x, y, z,
              x + lx, y + ly , z + lz,
              0.0f, 1.0f, 0.0f);



    draw();


    glutSwapBuffers();
}

// process user input, code taken from https://community.khronos.org/t/glutkeyboardfunc-problem/68033
void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.5f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
        case GLUT_KEY_F1 :
            //z += lz * fraction;
            y += (ly +1) * fraction;
            break;
        case GLUT_KEY_F2 :
            //z -= lz * fraction ;
            y -= (ly +1)* fraction;
            break;
    }

}
void changeSize(int w, int h) {

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

// Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

// Reset Matrix
    glLoadIdentity();

// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

// Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

// Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}


void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27)
        exit(0);
}


int main(int argc, char **argv) {

    // init GLUT and create window

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,600);
    glutCreateWindow("user input");
    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    // OpenGL init
    //+++++++++++++++++++Start light parameters+++++++++++++++++++++++++++++++++++++
   /* glEnable(GL_CULL_FACE);
    */
    glEnable(GL_LIGHT_MODEL_AMBIENT);
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0); // Variable for the ambient light
    glEnable(GL_LIGHT1);
    //+++++++++++++++++++End light parameters+++++++++++++++++++++++++++++++++++++++
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}