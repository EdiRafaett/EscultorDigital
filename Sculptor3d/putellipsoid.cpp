#include "putellipsoid.h"
#include <cmath>


/*=====Implementação da subclasse PutEllipsoid=====*/
PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int raiox, int raioy, int raioz, float r, float g, float b, float a) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raiox = raiox;
    this -> raioy = raioy;
    this -> raioz = raioz;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutEllipsoid::~PutEllipsoid() {

}

void PutEllipsoid::draw(Sculptor &s) {

    s.setColor(r, g, b, a);

    for (int i = (xcenter - raiox); i < (xcenter + raiox); i++) {
        for (int j = (ycenter - raioy); j < (ycenter + raioy); j++) {
            for (int k = (zcenter - raioz); k < (zcenter + raioz); k++) {
                if ((pow(i - xcenter, 2) / pow(raiox, 2)) + (pow(j - ycenter, 2) / pow(raioy, 2)) + (pow(k - zcenter, 2) / pow(raioz, 2)) <= 1) {
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
}
