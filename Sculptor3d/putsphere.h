#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/*=====Declaração da subclasse PutSphere=====*/
class PutSphere : public FiguraGeometrica{ //Herdeira de FiguraGeometrica
private:
    int xcenter, ycenter, zcenter, raio;

public:
    PutSphere(int xcenter, int ycenter, int zcenter, int raio,
              float r, float g, float b, float a); //Construtor da subclasse
    ~PutSphere(); //Destrutor da subclasse
    void draw(Sculptor &s); //Método Draw da subclasse com referencia para objeto da classe Sculptor
};

#endif
