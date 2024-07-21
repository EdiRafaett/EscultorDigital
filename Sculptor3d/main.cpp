#include <iostream>
#include <vector>
#include "sculptor.h"
#include "interpretador.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "cutvoxel.h"
#include "putsphere.h"


using namespace std;

int main() {

    Sculptor *Escultor;

    Interpretador Entrada;

    vector<FiguraGeometrica*> figs; //uso de container sequencial contido em STL
    //"vector" permite qualquer tipo e tamanho indefinido

    figs = Entrada.analise("arquivos/planetparameters.txt");
//Define o espaço de desenho
    Escultor = new Sculptor(Entrada.getDimx(), Entrada.getDimy(), Entrada.getDimz());

    for(size_t i = 0; i < figs.size(); i++) {

        cout << "draw\n";

        figs[i]->draw(*Escultor);
    } //execução dos desenhos das subclasses

    Escultor->writeOFF((char *) "arquivos/planeta.off");

    for(size_t i = 0; i < figs.size(); i++) {

        delete figs[i];
    }

    delete Escultor;

    return 0;
}
