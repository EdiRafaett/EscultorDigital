#include "putellipsoid.h"
#include <cmath>

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

    int i;
    int j;
    int k;

    s.setColor(r, g, b, a);

    for (i = (xcenter - raiox); i < (xcenter + raiox); i++) {

        for (j = (ycenter - raioy); j < (ycenter + raioy); j++) {

            for (k = (zcenter - raioz); k < (zcenter + raioz); k++) {

                if ((pow(i - xcenter, 2) / pow(raiox, 2)) + (pow(j - ycenter, 2) / pow(raioy, 2)) + (pow(k - zcenter, 2) / pow(raioz, 2)) <= 1) {

                    s.putVoxel(i, j, k);
                }
            }
        }
    }
} //draw irá passar como argumento o que foi atribuído pelo construtor, nos atributos da classe herdeira, para os parâmetros dos métodos de sculptor
