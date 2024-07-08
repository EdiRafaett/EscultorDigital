#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
/*=====Declaração da super classe abstrata FiguraGeometrica=====*/
class FiguraGeometrica {

//Variáveis protected para que as classes herdeiras tenham acesso
protected:
    float r, g, b, a;

public:
    FiguraGeometrica (); //Construtor da classe
    virtual ~FiguraGeometrica () {} //Destruidor de figura geométrica virtual (indicando polimorfismo)
    virtual void draw (Sculptor &s)=0; //Método Draw virtual puro com referencia para objeto da classe Sculptor
};

#endif
