#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"


class PutEllipsoid : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raiox;
    int raioy;
    int raioz;

public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int raiox, int raioy, int raioz, float r, float g, float b, float a);
    ~PutEllipsoid();
    void draw(Sculptor &s);
};

#endif
