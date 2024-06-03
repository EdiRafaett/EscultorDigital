#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <opencv2/opencv.hpp>

class Sculptor {

protected:
    Voxel *** v; //ponteiro para ponteiro para ponteiro do tipo struct Voxel
    int nx; //dimensão X da matriz
    int ny; //dimensão Y da matriz
    int nz; //dimensão Z da matriz
    float r; //define tom red de cada voxel
    float g; //define tom green de cada voxel
    float b; //define tom blue de cada voxel
    float a; //define transparência de cada voxe


public:
    Sculptor(int _nx, int _ny, int _nz); //construtor responsável por inicializar o objeto
    ~Sculptor(); //destrutor responsável por finalizar o objeto
    void setColor(float r, float g, float b, float alpha); //seleciona cor do voxel
    void putVoxel(int x, int y, int z); //ativa um voxel em (x,y,z)
    void cutVoxel(int x, int y, int z); //retira um voxel (x,y,z)
    void writeOFF(char *filename); //grava a escultura em um arquivo
};

#endif
