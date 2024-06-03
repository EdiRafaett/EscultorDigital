#include "puttextureonsphere.h"
#include "cmath"
#include "vector"
#include <opencv2/opencv.hpp>

PutTextureOnSphere::PutTextureOnSphere(int xcenter, int ycenter, int zcenter, int raio, cv::Mat &image) {
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutTextureOnSphere::~PutSphere() {

}

void PutTextureOnSphere::draw(Sculptor &s) {

    int i;
    int j;
    int k;

    s.setColor(r, g, b, a); //acesso do método de seleção de cor

    for (i = ((xcenter - raio)); i < (xcenter + raio); i++) {

        for (j = (ycenter - raio); j < (ycenter + raio); j++) {

            for (k = (zcenter - raio); k < (zcenter + raio); k++) {

                if ((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(raio, 2))) {
                    s.putVoxel(i, j, k); //acesso do método de inserção de voxel
                }
            }
        }
    }
}
}
