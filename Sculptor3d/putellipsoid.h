#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaraçã da subclasse PutEllipsoid=====*/
class PutEllipsoid : public FiguraGeometrica{ //Herdeira de FiguraGeometrica
private:
    int xcenter, ycenter, zcenter, raiox, raioy, raioz;

public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter,
                 int raiox, int raioy, int raioz, float r,
                 float g, float b, float a); //Construtor da subclasse
    ~PutEllipsoid(); //destrutor da subclasse
    void draw(Sculptor &s); //Método de desenho draw com referencia para objeto da classe Sculptor
};

#endif
