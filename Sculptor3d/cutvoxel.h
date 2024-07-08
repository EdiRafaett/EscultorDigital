#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"
/*=====Declaração da subclasse CutVoxel=====*/
class CutVoxel : public FiguraGeometrica{ //Herdeira de FiguraGeometrica
private:
    int x, y, z;

public:
    CutVoxel(int x, int y, int z); //construtor da subclasse
    ~CutVoxel(); //Destruidor da subclasse
    void draw(Sculptor &s); //método draw com referencia para objeto da classe Sculptor
};

#endif
