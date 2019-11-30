//
// Created by valentin on 08/10/19.
//

#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>


void draw() {

    //**********************************VAR DEFINITIONS*****************************************

    GLfloat matShininessSpec[] =  {500.0};
    GLfloat matLightColor[] = {0,0,0,1};
    //glMaterialfv(GL_FRONT, GL_SPECULAR,matSpecular);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT);
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininessSpec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,matLightColor);
    // Static ambient light, you may change it to any color youd like
    GLfloat ambientParams[] = {0, 0, 0, 0}; //Ambient light {r,g,b,alpha}

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientParams);
    //glLightfv(GL_LIGHT1,GL_POSITION,light_position);

    //*******************************************************************************************

    for (float i = -10; i < 0; ++i) { //draw the central spheres
        glPushMatrix();
        glTranslatef(0.0f ,0.0f, -10.0f);
        glutSolidSphere(10.0f/(-i),20,20);
    }


    glPopMatrix();
    glBegin(GL_LINE_STRIP);
    glLineWidth(GL_MAX);

    /*float lineR = 0.0;
    float lineG = 0.0;
    float lineB = 130.0;*/
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
        /*if(ii > 0){
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
        }*/
        //glColor3f(lineR,lineG,lineB);
        glVertex3d(xc , yc , zc);//output vertex

    }
    glEnd();


    for(int ii = 0; ii < 30/0.01; ii++) //loop for the incoming pointed tetrahedrons in the top of a pointed spiral
    {
        glBegin(GL_LINES);
        glLineWidth(GL_MAX);
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = (radius)* cosf(theta);//calculate the x component
        float y = (radius )* sinf(theta);//calculate the y component
        //creates spiral effect
        zc += 0.03f;
        radius -= 0.01f;
        //set the color schema
       /* lineR += 0.001f;
        lineG -= 0.01f;
        lineB -= 0.01f;
        glColor3f(lineR,lineG,lineB);*/
        if (ii %2 != 0){ //draw the tetrahedrons
            glEnd();
            glPushMatrix();
            glTranslatef(x,y,zc);
            //glutSolidCone(0.5,10,10,10);
            glutSolidTetrahedron();
            glPopMatrix();
        }
        glVertex3d(x , y , zc);//output vertex

    }
    //glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
/*
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
    glVertex3f(-1000,-100,1000);
    glVertex3f(1000,-100,1000);
    glVertex3f(1000,100,1000);
    glVertex3f(-1000,100,1000);

    glVertex3f(-1000,-100,-100);
    glVertex3f(1000,-100,-100);
    glVertex3f(1000,100,-100);
    glVertex3f(-1000,100,-100);

    glVertex3f(1000,100,1000);
    glVertex3f(1000,-100,1000);
    glVertex3f(1000,-100,-100);
    glVertex3f(1000,100,-100);

    glVertex3f(-1000,100,10);
    glVertex3f(-1000,-100,10);
    glVertex3f(-1000,-100,-10);
    glVertex3f(-1000,100,-10);
*/
    glEnd();

}
void addLight(float x,float y,float z,float lx, float ly, float lz){
    GLfloat matShininess[] =  {120.0};
    GLfloat matSpecular[] =  {1.0,1.0,0,1.0}; //TODO:  cambiar estos por variables para controlar el color de la luz
    GLfloat light_position[] =  {x, y, z, 0.0};
    GLfloat light_direction[] =  {lx, ly, lz, 0.0};
    GLfloat attentuation[] =  {50.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR,matSpecular);
    glMaterialfv(GL_FRONT,GL_SHININESS,matShininess);

    glLightfv(GL_LIGHT2,GL_POSITION,light_position);
    glLightfv(GL_LIGHT2,GL_SPECULAR,matSpecular);
    glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,light_direction);
    glLightfv(GL_LIGHT2,GL_LINEAR_ATTENUATION,attentuation);
    glEnable(GL_LIGHT2);
}

