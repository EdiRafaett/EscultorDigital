#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int raio) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;

}

CutSphere::~CutSphere() {

}

void CutSphere::draw(Sculptor &s) {
    for (int i = xcenter - raio; i <= xcenter + raio; i++) {
        for (int j = ycenter - raio; j <= ycenter + raio; j++) {
            for (int k = zcenter - raio; k <= zcenter + raio; k++) {
                if ((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(raio, 2))) {
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
 //draw irá passar como argumento o que foi atribuído pelo construtor, nos atributos da classe herdeira, para os parâmetros dos métodos de sculptor
