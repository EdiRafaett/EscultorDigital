#include "putplanet.h"
#include <iostream>
#include <cmath> //funções matemáticas
#include <fstream> //inclusão do fluxo para arquivos
#include <cstdlib> //inclusão da função exit
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

PutPlanet::PutPlanet(int xcenter, int ycenter, int zcenter, int raio, std::string caminhoimg) {

    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;
    image = cv::imread(caminhoimg);

}

PutPlanet::~PutPlanet() {

}

void PutPlanet::draw(Sculptor &s) {

    int i;
    int j;
    int k;

   // s.setColor(r, g, b, a); //acesso do método de seleção de cor

    for (i = ((xcenter - raio)); i < (xcenter + raio); i++) {

        for (j = (ycenter - raio); j < (ycenter + raio); j++) {

            for (k = (zcenter - raio); k < (zcenter + raio); k++) {

                if ((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(raio, 2))) {
                    s.putVoxel(i, j, k); //acesso do método de inserção de voxel
                    double theta = atan2(j - ycenter, i - xcenter);
                    double phi = acos((k - zcenter) / (double)raio);
                    // Mapeamento das coordenadas esféricas para as coordenadas da imagem:
                    int u = image.cols * (theta + M_PI) / (2 * M_PI); //theta
                    int v = image.rows * phi / M_PI; //phi
                    // color recebe as cores dos pixels:
                    cv::Vec3b color = image.at<cv::Vec3b>(v, u);
                    // Atribuição dessas cores ao voxel:
                    this -> r = color[2]; // R
                    this -> g = color[1]; // G
                    this -> b = color[0]; // B
                    //this -> a = 1;
                    s.setColor(r, g, b, a); //acesso do método de seleção de cor
                    s.putVoxel(i, j, k); //acesso do método de inserção de voxel
                }
            }
        }
    }
}
