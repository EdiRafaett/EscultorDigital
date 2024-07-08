#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaração da subclasse FiguraGeometrica======*/
class CutBox : public FiguraGeometrica{ //Herdeira de FiguraGeometrica

private:
    int x0, x1, y0, y1, z0, z1;

public:
    CutBox(int x0, int x1,
           int y0, int y1,
           int z0, int z1); //Construtor da subclasse
    ~CutBox(); //Destruidor da subclasse
    void draw(Sculptor &s); //Método draw com referencia para objeto da classe Sculptor
};

#endif
