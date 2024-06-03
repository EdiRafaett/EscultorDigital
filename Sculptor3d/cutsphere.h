#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raio;

public:
    CutSphere(int xcenter, int ycenter, int zcenter, int raio);
    ~CutSphere();
    void draw(Sculptor &s);
};

#endif
