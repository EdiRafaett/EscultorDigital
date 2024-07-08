#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaração da subclasse CutSphere:=====*/
class CutSphere : public FiguraGeometrica{ //Herdeira de FiguraGeometrica

private:
    int xcenter, ycenter, zcenter, raio;

public:
    CutSphere(int xcenter, int ycenter, int zcenter, int raio); //Construtor da subclasse
    ~CutSphere(); //Destruidor da subclasse
    void draw(Sculptor &s); //método draw com referencia para objeto da classe Sculptor
};

#endif
