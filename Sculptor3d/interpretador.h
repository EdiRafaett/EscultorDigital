#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <string>
#include <vector>
#include "figurageometrica.h"

using namespace std;

/*=====Declaração da classe Interpretador=====*/
class Interpretador {
private:
    int dimx, dimy, dimz;
    float r, g, b, a;

public:
    Interpretador(); //Construtor da classe
    vector<FiguraGeometrica*> analise(string filename); // Método analise que recebe um nome de arquivo como argumento e retorna um vetor de ponteiros para objetos FiguraGeometrica
    int getDimx(); // método para a dimensão x
    int getDimy(); // método para a dimensão y
    int getDimz(); // método para a dimensão z
};

#endif
