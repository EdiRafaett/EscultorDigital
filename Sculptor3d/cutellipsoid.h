#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaração da subclasse CutEllipsoid=====*/
class CutEllipsoid : public FiguraGeometrica{ //Herdeira de FiguraGeometrica

private:
    int xcenter, ycenter, zcenter, raiox, raioy, raioz;

public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter,
                 int raiox, int raioy, int raioz); //Construtor da subclasse
    ~CutEllipsoid(); //Destruidor da subclasse
    void draw(Sculptor &s); //Método draw com referencia para objeto da classe Sculptor
};

#endif
