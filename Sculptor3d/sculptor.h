#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <opencv2/opencv.hpp>

/*=====Declaração da classe Sculptor (escultor da classe):=====*/
class Sculptor {

//Variáveis protected para as classes herdeiras terem acesso
protected:
    Voxel *** v; //ponteiro para ponteiro para ponteiro do tipo Voxel
    int nx, ny, nz; //dimensão X, Y, Z da matriz
    float r, g, b, a; //define cores r, g, b e trasparência alpha

//Métodos da classe Sculptor:
public:
    Sculptor(int _nx, int _ny, int _nz); //construtor responsável por inicializar o objeto
    ~Sculptor(); //destrutor responsável por finalizar o objeto
    void setColor(float r, float g, float b, float alpha); //Seleciona a cor dos voxels
    void putVoxel(int x, int y, int z); //ativa um voxel nas coordenadas (x,y,z)
    void cutVoxel(int x, int y, int z); //retira um voxel nas coordenadas (x,y,z)
    void writeOFF(char *filename); //grava a escultura em um arquivo
};

#endif
