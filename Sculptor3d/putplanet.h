#ifndef PUTPLANET_H
#define PUTPLANET_H
#include "figurageometrica.h"
#include "sculptor.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

class PutPlanet : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raio;
    cv::Mat image;
public:
    PutPlanet(int xcenter, int ycenter, int zcenter, int raio, std::string caminhoimg);
    ~PutPlanet();
    void draw(Sculptor &s);
};

#endif // PUTPLANET_H
