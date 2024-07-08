#include "putsphere.h"
#include <cmath>


/*=====Implementação da subclasse PutSphere=====*/
PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int raio, float r, float g, float b, float a) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutSphere::~PutSphere() {

}

void PutSphere::draw(Sculptor &s) {

    s.setColor(r, g, b, a); //acesso do método de seleção de cor

    for (int i = ((xcenter - raio)); i < (xcenter + raio); i++) {
        for (int j = (ycenter - raio); j < (ycenter + raio); j++) {
            for (int k = (zcenter - raio); k < (zcenter + raio); k++) {
                if ((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(raio, 2))) {
                    s.putVoxel(i, j, k); //acesso do método de inserção de voxel
                }
            }
        }
    }
}
