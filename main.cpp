#include <GL/glut.h>
#include <math.h>
#include "draw.h"

int fase = 0;
float MSECS = 100.0;

int INICIO_DESARROLLO = 2200;
int FIN_DESARROLLO = 23500;
int FIN_CIERRE = 28500;
float SEGMENTOS_POR_DEFECTO = 500; //Segmentos para tener un círculo completamente redondo




void display(int c){

    float tiempoTranscurrido = fase*MSECS;
    float variableSenoidalColores = abs(255 * sin(fase*0.1)); //Senoidal que rige el cambio periodico de color en cada baldoza
    float variableSenoidalMutacion = abs(10*sin(fase*0.1));  //Senoidal que rige el número de segmentos al que mutarán
    // los círculos de la baldoza
    glClear(GL_COLOR_BUFFER_BIT);

//               ************ INTRODUCCIÓN ************


    if(tiempoTranscurrido > 0) { //Dibujamos baldoza central segmento por segmento (desmembrado)
        dibujaCuadroTrasero();
    }
    if(tiempoTranscurrido > 500){
        dibujaCuadroFrontal();
    }
    if(tiempoTranscurrido > 1000){
        dibujaCirculoInferior();
        dibujaCirculoSuperior();
    }
    if(tiempoTranscurrido > 1500){
        dibujaCirculoIzquierdo();
        dibujaCirculoDerecho();
    }
    if(tiempoTranscurrido > 2000){    //se agrega el último elemento de baldoza central y se pintan las adyacentes
        dibujaTextura();
        dibujaBaldoza(-250, 0, 180, 189, 187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 0, 180, 189, 187,SEGMENTOS_POR_DEFECTO);
    }
    if(tiempoTranscurrido > 2100){
        dibujaBaldoza(0, 250, 180, 189, 187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(0, -250, 180, 189, 187,SEGMENTOS_POR_DEFECTO);
    }
    if(tiempoTranscurrido > INICIO_DESARROLLO){
        dibujaBaldoza(0,0,135,189,187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 250, 45, 189, 187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, -250, 45, 189, 187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, 250, 45, 189, 187,SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, -250, 45, 189, 187,SEGMENTOS_POR_DEFECTO);
    }

    //               ************ DESARROLLO DE LA HISTORIA ************

    /*Se cambia a modo cámara, hacemos una rotación y se regresa a alteraciones del modelo*/
    if(tiempoTranscurrido > 2500 && tiempoTranscurrido < 10500) {

        glMatrixMode(GL_PROJECTION);
        glRotatef(3, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        dibujaBaldoza(-250, 0, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 0, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(0, 250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(0, -250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 250, 45, 189, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, -250, 45, 189, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, 250, 45, 189, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, -250, 45, 189, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
    }
    if(tiempoTranscurrido > 10500 && tiempoTranscurrido< 15500 ){
        glMatrixMode(GL_PROJECTION);
        glRotatef(-3, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        dibujaBaldoza(-250, 0, 180, variableSenoidalColores, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 0, 180, variableSenoidalColores, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(0, 250, 180, variableSenoidalColores, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(0, -250, 180, variableSenoidalColores, variableSenoidalColores, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, 250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, -250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(-250, 250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
        dibujaBaldoza(250, -250, variableSenoidalColores, 189, 187, SEGMENTOS_POR_DEFECTO);
    }
    if(tiempoTranscurrido > 15500 && tiempoTranscurrido < 18600){
        //rotamos la baldoza hacia otro lado, comenzamos mutaciones en cŕculos, semicírculos y cambiamos colores
        glMatrixMode(GL_PROJECTION);
        glRotatef(-3, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
    }
    if(tiempoTranscurrido > 15500 && tiempoTranscurrido < FIN_DESARROLLO){ //paramos la rotación
        dibujaBaldoza(-250, 0, 180, variableSenoidalColores, variableSenoidalColores, variableSenoidalMutacion);
        dibujaBaldoza(250, 0, 180, variableSenoidalColores, variableSenoidalColores, variableSenoidalMutacion);
        dibujaBaldoza(0, 250, 180, variableSenoidalColores, variableSenoidalColores, variableSenoidalMutacion);
        dibujaBaldoza(0, -250, 180, variableSenoidalColores, variableSenoidalColores, variableSenoidalMutacion);
        dibujaBaldoza(250, 250, variableSenoidalColores, 189, 187, variableSenoidalMutacion);
        dibujaBaldoza(-250, -250, variableSenoidalColores, 189, 187, variableSenoidalMutacion);
        dibujaBaldoza(-250, 250, variableSenoidalColores, 189, 187, variableSenoidalMutacion);
        dibujaBaldoza(250, -250, variableSenoidalColores, 189, 187, variableSenoidalMutacion);
    }

    //               ************ FIN DE LA HISTORIA ************


    if(tiempoTranscurrido > FIN_DESARROLLO && tiempoTranscurrido < 25500){ //volvemos fondos blancos para apreciar mutaciones
        dibujaBaldoza(-250, 0, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(250, 0, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(0, 250, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(0, -250, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(250, 250, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(-250, -250, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(-250, 250, 255, 255, 255, variableSenoidalMutacion);
        dibujaBaldoza(250, -250, 255, 255, 255, variableSenoidalMutacion);
    }
    if(tiempoTranscurrido > 25500){ //dibujamos cuadros blancos para la salida
        dibujaCuadroBlanco(-250, 0 );
        dibujaCuadroBlanco(250, 0);
    }
    if(tiempoTranscurrido > 26000 ){
        dibujaCuadroBlanco(0, 250 );
        dibujaCuadroBlanco(0, -250);
    }
    if(tiempoTranscurrido > 26500 ){
        dibujaCuadroBlanco(250, 250 );
        dibujaCuadroBlanco(-250, -250);
    }
    if(tiempoTranscurrido > 27000 ){
        dibujaCuadroBlanco(-250, 250 );
        dibujaCuadroBlanco(250, -250);
    }
    if(tiempoTranscurrido > FIN_CIERRE) {
        dibujaCuadroBlanco(0, 0);
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