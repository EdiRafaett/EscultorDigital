#ifndef PUTTEXTUREONSPHERE_H
#define PUTTEXTUREONSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"
#include <opencv2/opencv.hpp>

class PutTextureOnSphere : public FiguraGeometrica
{
public:
    PutTextureOnSphere(int xcenter, int ycenter, int zcenter, int raio, cv::Mat &image);
    ~PutTextureOnSphere();
    void draw(Sculptor &s);
};

#endif // PUTTEXTUREONSPHERE_H
