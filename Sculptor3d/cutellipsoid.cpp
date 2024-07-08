#include "cutellipsoid.h"
#include <cmath>

/*=====Implementação da subclasse CutEllipsoid=====*/
CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int raiox, int raioy, int raioz) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raiox = raiox;
    this -> raioy = raioy;
    this -> raioz = raioz;

}

CutEllipsoid::~CutEllipsoid() {}

void CutEllipsoid::draw(Sculptor &s) {

    for (int i = 0; i < raiox; i++) {
        for (int j = 0; j < raioy; j++) {
            for (int k = 0; k < raioz; k++) {
                if ((pow(i - xcenter, 2) / pow(raiox, 2)) + (pow(j - ycenter, 2) / pow(raioy, 2)) + (pow(k - zcenter, 2) / pow(raioz, 2)) <= 1) {
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
