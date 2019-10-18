//
// Created by valentin on 08/10/19.
//

#include <GL/gl.h>
#include <math.h>
float radioCirculos = 62.0;
float segmentosStdr = 500;

float matrizDeDibujo[][2] = {{508.0,192.0},//0: gran circulo central inferior
                             {508.0,312.0},//1: gran circulo central superior
                             {448.0,251.0},//2: gran circulo izquierdo
                             {566.0,251.0},//3: gran circulo derecho
                             {450.0,135.0},//4: medio circulo inferior izquierdo
                             {567.0,135.0},//5: medio circulo inferior derecho
                             {450.0,368.0},//6: medio circulo superior izquierdo
                             {567.0,368.0},//7: medio circulo superior derecho
                             {390.0,313.0},//8: medio circulo lateral izquierdo superior
                             {390.0,198.0},//9: medio circulo lateral izquierdo inferior
                             {624.0,313.0},//10: medio circulo lateral derecho superior
                             {624.0,198.0},//11: medio circulo lateral derecho inferior
                             {382,127},//12: cuadro trasero
                             {632,127},//13: cuadro trasero
                             {632,380},//14: cuadro trasero
                             {382,380},//15: cuadro trasero
                             {394,138},//16: cuadro frontal
                             {621,138},//17: cuadro frontal
                             {621,364},//18: cuadro frontal
                             {393,364}//19 cuadro frontal
};
float matrizDeAnimacion[][2] = {{508.0,192.0},//0: gran circulo central inferior
                             {508.0,312.0},//1: gran circulo central superior
                             {448.0,251.0},//2: gran circulo izquierdo
                             {566.0,251.0},//3: gran circulo derecho
                             {450.0,135.0},//4: medio circulo inferior izquierdo
                             {567.0,135.0},//5: medio circulo inferior derecho
                             {450.0,368.0},//6: medio circulo superior izquierdo
                             {567.0,368.0},//7: medio circulo superior derecho
                             {390.0,313.0},//8: medio circulo lateral izquierdo superior
                             {390.0,198.0},//9: medio circulo lateral izquierdo inferior
                             {624.0,313.0},//10: medio circulo lateral derecho superior
                             {624.0,198.0},//11: medio circulo lateral derecho inferior
                             {382,127-380},//12: cuadro trasero
                             {632,127-380},//13: cuadro trasero
                             {632,380-380},//14: cuadro trasero
                             {382,380-380},//15: cuadro trasero
                             {394,138+512},//16: cuadro frontal
                             {621,138+512},//17: cuadro frontal
                             {621,364+512},//18: cuadro frontal
                             {393,364+512}//19 cuadro frontal
};

void dibujaCuadro(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float r,float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);


    glEnd();
}
void dibujaCirculo(float cx, float cy, float r, float num_segments){//hecho con la ayuda de https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
    glColor3f(68.0/255.0,141.0/255.0,136.0/255.0);
    glLineWidth(50);
    glBegin(GL_LINE_LOOP);
    for(float ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * ii /num_segments;

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void dibujaCirculoPequeno(float cx, float cy, float r, float num_segments){//hecho con la ayuda de https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
    glColor3f(35.0/255.0,69.0/255.0,58.0/255.0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for(float ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * ii /num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void dibujaMedioCirculo(float cx, float cy, float r, float num_segments,float dir, bool vertical){
    glColor3f(68.0/255.0,141.0/255.0,136.0/255.0);
    glLineWidth(40.0);
    glBegin(GL_LINE_LOOP);
    for(float ii = 0; ii < num_segments; ii++)
    {
        float theta = dir*3.1415926f * ii /num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);

        if(vertical){
            float temp = x;
            x = y;
            y = temp;
        }
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void dibujaCuadroTrasero(){    dibujaCuadro( //cuadro trasero
            matrizDeDibujo[12][0],matrizDeDibujo[12][1],
            matrizDeDibujo[13][0],matrizDeDibujo[13][1],
            matrizDeDibujo[14][0],matrizDeDibujo[14][1],
            matrizDeDibujo[15][0],matrizDeDibujo[15][1],
            68.0/255.0,141.0/255.0,136.0/255.0);
}
void dibujaCuadroFrontal(){ dibujaCuadro( //cuadro frontal
            matrizDeDibujo[16][0],matrizDeDibujo[16][1],
            matrizDeDibujo[17][0],matrizDeDibujo[17][1],
            matrizDeDibujo[18][0],matrizDeDibujo[18][1],
            matrizDeDibujo[19][0],matrizDeDibujo[19][1],
            135.0/255.0,189.0/255.0,187.0/255.0);
}
void dibujaCirculoSuperior(){
    dibujaCirculo(matrizDeDibujo[1][0],matrizDeDibujo[1][1],radioCirculos,segmentosStdr);
}
void dibujaCirculoInferior(){
    dibujaCirculo(matrizDeDibujo[0][0],matrizDeDibujo[0][1],radioCirculos,segmentosStdr);
}
void dibujaCirculoIzquierdo(){
    dibujaCirculo(matrizDeDibujo[2][0],matrizDeDibujo[2][1],radioCirculos,segmentosStdr);
}
void dibujaCirculoDerecho(){
    dibujaCirculo(matrizDeDibujo[3][0],matrizDeDibujo[3][1],radioCirculos,segmentosStdr);
}
void dibujaMediosCirculos(){
    dibujaMedioCirculo(matrizDeDibujo[4][0],matrizDeDibujo[4][1],radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[5][0],matrizDeDibujo[5][1],radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[6][0],matrizDeDibujo[6][1],radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[7][0],matrizDeDibujo[7][1],radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[8][0],matrizDeDibujo[8][1],radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[9][0],matrizDeDibujo[9][1],radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[10][0],matrizDeDibujo[10][1],radioCirculos,segmentosStdr,-1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[11][0],matrizDeDibujo[11][1],radioCirculos,segmentosStdr,-1.0,1);
}

void draw(float x,float y){
    float radioCirculos = 62.0;
    float segmentosStdr = 500;


    dibujaCuadro( //cuadro trasero
            matrizDeDibujo[12][0] +x,matrizDeDibujo[12][1]+y,
            matrizDeDibujo[13][0]+x,matrizDeDibujo[13][1]+y,
            matrizDeDibujo[14][0]+x,matrizDeDibujo[14][1]+y,
            matrizDeDibujo[15][0]+x,matrizDeDibujo[15][1]+y,
            68.0/255.0,141.0/255.0,136.0/255.0);

    dibujaCuadro( //cuadro frontal
            matrizDeDibujo[16][0]+x,matrizDeDibujo[16][1]+y,
            matrizDeDibujo[17][0]+x,matrizDeDibujo[17][1]+y,
            matrizDeDibujo[18][0]+x,matrizDeDibujo[18][1]+y,
            matrizDeDibujo[19][0]+x,matrizDeDibujo[19][1]+y,
            135.0/255.0,189.0/255.0,187.0/255.0);

    dibujaCirculo(matrizDeDibujo[0][0]+x,matrizDeDibujo[0][1]+y,radioCirculos,segmentosStdr);//central inferior
    dibujaCirculo(matrizDeDibujo[1][0]+x,matrizDeDibujo[1][1]+y,radioCirculos,segmentosStdr);//central superior
    dibujaCirculo(matrizDeDibujo[2][0]+x,matrizDeDibujo[2][1]+y,radioCirculos,segmentosStdr);//izquierdo
    dibujaCirculo(matrizDeDibujo[3][0]+x,matrizDeDibujo[3][1]+y,radioCirculos,segmentosStdr);//derecho
    dibujaMedioCirculo(matrizDeDibujo[4][0]+x,matrizDeDibujo[4][1]+y,radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[5][0]+x,matrizDeDibujo[5][1]+y,radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[6][0]+x,matrizDeDibujo[6][1]+y,radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[7][0]+x,matrizDeDibujo[7][1]+y,radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[8][0]+x,matrizDeDibujo[8][1]+y,radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[9][0]+x,matrizDeDibujo[9][1]+y,radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[10][0]+x,matrizDeDibujo[10][1]+y,radioCirculos,segmentosStdr,-1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[11][0]+x,matrizDeDibujo[11][1]+y,radioCirculos,segmentosStdr,-1.0,1);
    dibujaCirculoPequeno(matrizDeDibujo[0][0]+x,matrizDeDibujo[0][1]+y,7.0,segmentosStdr);
    dibujaCirculoPequeno(matrizDeDibujo[1][0]+x,matrizDeDibujo[1][1]+y,7.0,segmentosStdr);
    dibujaCirculoPequeno(matrizDeDibujo[2][0]+x,matrizDeDibujo[2][1]+y,7.0,segmentosStdr);
    dibujaCirculoPequeno(matrizDeDibujo[3][0]+x,matrizDeDibujo[3][1]+y,7.0,segmentosStdr);

    glFlush();
}