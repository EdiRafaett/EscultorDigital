#ifndef PUTEARTH_H
#define PUTEARTH_H
#include "figurageometrica.h"
#include "sculptor.h"
#include "iostream"
#include <string>
#include <opencv2/opencv.hpp>

class PutEarth : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int raio;
    cv::Mat image;
public:
    PutEarth(int xcenter, int ycenter, int zcenter, int raio, std::string filename);
    ~PutEarth();
    void draw(Sculptor &s);

};

#endif // PUTEARTH_H
