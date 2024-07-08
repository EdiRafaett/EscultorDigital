#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaração da subclasse PutBox=====*/
class PutBox : public FiguraGeometrica{ //Herdeira de FiguraGeometrica

private:
    int x0, x1, y0, y1, z0, z1;

public:
    PutBox(int x0, int x1, int y0, int y1,
           int z0, int z1,
           float r, float g, float b, float a); //Construtor da subclasse
    ~PutBox(); //Destrutor da subclasse
    void draw(Sculptor &s); //Método draw com refencia para objeto da classe Sculptor
};

#endif
