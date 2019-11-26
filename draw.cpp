//
// Created by valentin on 08/10/19.
//

#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>

void draw() {

    glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
    GLubyte texArray [0][32][4];
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, texArray);
    //glColor3f(0,0,1);
    for (float i = -10; i < 0; ++i) { //draw the central spheres
        glPushMatrix();
        glTranslatef(0.0f ,0.0f, -10.0f);
        glEnable(GL_TEXTURE_2D);
        glutSolidSphere(10.0f/(-i),20,20);
        glDisable(GL_TEXTURE_2D);

    }
    glPopMatrix();
    glBegin(GL_LINE_STRIP);
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


    for(int ii = 0; ii < 30/0.01; ii++) //loop for the incoming pointed tetrahedrons in the top of a pointed spiral
    {
        glBegin(GL_LINES);
        glLineWidth(GL_MAX);
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = (radius-25)* cosf(theta);//calculate the x component
        float y = (radius-25 )* sinf(theta);//calculate the y component
        //creates spiral effect
        zc += 0.01f;
        radius -= 0.01f;
        //set the color schema
        lineR += 0.001f;
        lineG -= 0.01f;
        lineB -= 0.01f;
        glColor3f(lineR,lineG,lineB);
        if (ii %2 != 0){ //draw the tetrahedrons
            glEnd();
            glPushMatrix();
            glTranslatef(x,y,zc);
            glutSolidTetrahedron();
            glPopMatrix();
        }
        glVertex3d(x , y , zc);//output vertex

    }
    glEnd();

}


