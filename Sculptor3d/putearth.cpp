#include "putearth.h"
#include "sculptor.h"
#include "iostream"

//#include <vector>
using namespace std;

PutEarth::PutEarth(int xcenter, int ycenter, int zcenter, int raio, std::string filename){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> raio = raio;
    image = cv::imread(filename);
}

PutEarth::~PutEarth(){

}

void PutEarth::draw(Sculptor &s) {
  //  s.setColor(r, g, b, a);
    int i, j, k;
    for (i = ((xcenter - raio)); i < (xcenter + raio); i++) {

        for (j = (ycenter - raio); j < (ycenter + raio); j++) {

            for (k = (zcenter - raio); k < (zcenter + raio); k++) {

                if ((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(raio, 2))) {
                    s.putVoxel(i, j, k); //acesso do método de inserção de voxel
                    if(image.empty()){
                        std:: cout << "Não foi possível abrir a imagem" << std::endl;
                    }
                    double theta = atan2(j - ycenter, i - xcenter);
                    double phi = acos((k - zcenter) / (double)raio);
                    // Mapeamento das coordenadas esféricas para as coordenadas da imagem:
                    int u = image.cols * (theta + M_PI) / (2 * M_PI); //theta
                    int v = image.rows * phi / M_PI; //phi
                    // color recebe as cores dos pixels:
                    cv::Vec3b color = image.at<cv::Vec3b>(v, u);
                    // Atribuição dessas cores ao voxel:
                    r = color[2]; // R
                    g = color[1]; // G
                    b = color[0]; // B
                    a = 1;
                }
            }
        }
    }
}
