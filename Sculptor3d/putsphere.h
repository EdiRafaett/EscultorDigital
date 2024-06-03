#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"


class PutSphere : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raio;

public:
    PutSphere(int xcenter, int ycenter, int zcenter, int raio, float r, float g, float b, float a);
    ~PutSphere();
    void draw(Sculptor &s);
};

#endif
