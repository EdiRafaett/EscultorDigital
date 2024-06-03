#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <string>
#include <vector>
#include "figurageometrica.h"

using namespace std;

class Interpretador {
private:
    int dimx;
    int dimy;
    int dimz;
    float r;
    float g;
    float b;
    float a;

public:
    Interpretador();
    vector<FiguraGeometrica*> analise(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif
