#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raiox;
    int raioy;
    int raioz;

public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int raiox, int raioy, int raioz);
    ~CutEllipsoid();
    void draw(Sculptor &s);
};

#endif
