#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"
/*=====Declaração da subclasse PutVoxel=====*/
class PutVoxel : public FiguraGeometrica{ //Herdeira de FiguraGeometrica
private:
    int x, y, z;

public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a); //Construtor da subclasse
    ~PutVoxel(); //Destrutor da subclasse
    void draw(Sculptor &s); //Declaração da função draw com referência para objeto da classe Sculptor

};

#endif
