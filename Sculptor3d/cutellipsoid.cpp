#include "cutellipsoid.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int raiox, int raioy, int raioz) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raiox = raiox;
    this -> raioy = raioy;
    this -> raioz = raioz;

}

CutEllipsoid::~CutEllipsoid() {

}

void CutEllipsoid::draw(Sculptor &s) {

    int i;
    int j;
    int k;

    for (i = 0; i < raiox; i++) {

        for (j = 0; j < raioy; j++) {

            for (k = 0; k < raioz; k++) {

                if ((pow(i - xcenter, 2) / pow(raiox, 2)) + (pow(j - ycenter, 2) / pow(raioy, 2)) + (pow(k - zcenter, 2) / pow(raioz, 2)) <= 1) {

                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
} //draw irá passar como argumento o que foi atribuído pelo construtor, nos atributos da classe herdeira, para os parâmetros dos métodos de sculptor
