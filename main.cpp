#include <GL/glut.h>
#include <cmath>


// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f, ly=0.0f;
// XZ position of the camera
float x=0.0f,z=-1.0f,y=1.0f;
void draw() {

    glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
    glTranslatef(0.0f ,0.75f, 0.0f);
    //glutSolidSphere(0.1f,20,20);


    glBegin(GL_LINE_LOOP);
    glLineWidth(GL_MAX);

    float lineR = 0.0;
    float lineG = 0.0;
    float lineB = 130.0;
    double zc = -80;
    float radius = 30;
    float radialDecrease = 0.01;
    for(int ii = 0; ii < 30/radialDecrease; ii++) //loop for the spiral, loop ii until the radius is 0
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle

        float xc = radius * cosf(theta);//calculate the x component
        float yc = radius * sinf(theta);//calculate the y component
        zc -= 0.005;
        radius -= radialDecrease;
        if(ii > 0){
            lineR +=0.001;
            lineB += 0.001;
        }
        if (ii > 1000 && ii < 1200){
            lineR += 0.001;
            lineG += 0.001;
            lineB -= 0.001;
        }
        if(ii >= 1200 && ii < 1400){
            lineR -= 0.002;
            lineG += 0.002;
            lineB -= 0.002;
        }
        if(ii >= 1400){
            lineR -= 0.002;
            lineG += 0.005;
            lineB -= 0.002;
        }
        glColor3f(lineR,lineG,lineB);
        glVertex3d(xc , yc , zc);//output vertex

    }
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(GL_MAX);

    for(int ii = 0; ii < 30/0.01; ii++) //loop for the incoming pointed lines
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = (radius-25)* cosf(theta);//calculate the x component
        float y = (radius-25 )* sinf(theta);//calculate the y component
        zc += 0.01f;
        radius -= 0.01f;
        lineR += 0.001f;
        lineG -= 0.01f;
        lineB -= 0.01f;
        glColor3f(lineR,lineG,lineB);
        if (ii %2 != 0){
            glPushMatrix();
            glTranslatef(x,y,zc);
            glutSolidTetrahedron();
            glPopMatrix();
        }
        glVertex3d(x , y , zc);//output vertex

    }
    glEnd();

}

void renderScene(void) {

    // Clear Color and Depth Buffers

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(x, y, z,
              x + lx, y + ly , z + lz,
              0.0f, 1.0f, 0.0f);


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
// Floor
    glVertex3f(-100,-100,-100);
    glVertex3f(100,-100,-100);
    glVertex3f(100,-100,1000);
    glVertex3f(-100,-100,1000);
    // Ceiling
    glVertex3f(-100,100,-100);
    glVertex3f(100,100,-100);
    glVertex3f(100,100,1000);
    glVertex3f(-100,100,1000);
    // Walls
    glVertex3f(-100,-100,1000);
    glVertex3f(100,-100,1000);
    glVertex3f(100,100,1000);
    glVertex3f(-100,100,1000);

    glVertex3f(-100,-100,-100);
    glVertex3f(100,-100,-100);
    glVertex3f(100,100,-100);
    glVertex3f(-100,100,-100);

    glVertex3f(100,100,1000);
    glVertex3f(100,-100,1000);
    glVertex3f(100,-100,-100);
    glVertex3f(100,100,-100);

    glVertex3f(-100,100,10);
    glVertex3f(-100,-100,10);
    glVertex3f(-100,-100,-10);
    glVertex3f(-100,100,-10);
    glEnd();
    draw();


    glutSwapBuffers();
}


void processSpecialKeys(int key, int xx, int yy) { // process user input, code found at https://community.khronos.org/t/glutkeyboardfunc-problem/68033

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
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("user input");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);


    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}