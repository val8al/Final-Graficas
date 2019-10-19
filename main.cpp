#include <GL/glut.h>

#include "draw.h"

int fase = 0;
float MSECS = 300.0;


void introCuadroTrasero(){ //Desplazamiento de abajo hacia arriba de cuadro trasero

}
void introCuadroFrontal(){
}
void display(int c){

    float tiempoTranscurrido = c*MSECS;
    glClear(GL_COLOR_BUFFER_BIT);

//               ************ INTRODUCCIÓN ************


    if(tiempoTranscurrido > 0) {
        dibujaCuadroTrasero();
        introCuadroTrasero();
    }
    if(tiempoTranscurrido > 500){
        dibujaCuadroFrontal();
        introCuadroFrontal();
    }
    if(tiempoTranscurrido > 1000){
        dibujaCirculoInferior();
        dibujaCirculoSuperior();
    }
    if(tiempoTranscurrido > 1500){
        dibujaCirculoIzquierdo();
        dibujaCirculoDerecho();
    }
    if(tiempoTranscurrido > 2000){
        dibujaTextura();
        //68,141,136//135,189,187
        draw(-250,0,180,189,187);
        draw(250,0,180,189,187);
    }
    if(tiempoTranscurrido > 2100){
        draw(0,250,180,189,187);
        draw(0,-250,180,189,187);
    }
    if(tiempoTranscurrido > 2200){
        draw(250,250,45,189,187);
        draw(-250,-250,45,189,187);
        draw(-250,250,45,189,187);
        draw(250,-250,45,189,187);
    }

    //               ************ DESARROLLO DE LA HISTORIA ************


    if(tiempoTranscurrido > 2500){
        draw(-250,0,180,189,187);

    }
    if(tiempoTranscurrido > 2350){

    }
    fase++;
    glutSwapBuffers();
    glutTimerFunc(MSECS, display, fase);

}


int main(int argc, char **argv){


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1024,512);
    glutCreateWindow ("miniproyecto2");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 1024.0, 0, 512.0);//0,1024,0,512

    glutTimerFunc(MSECS, display, fase);

    glutMainLoop();

    return 0;
}