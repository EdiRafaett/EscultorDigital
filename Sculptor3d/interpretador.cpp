#include <fstream>
#include <sstream>
#include <iostream>
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putplanet.h"

using namespace std;

Interpretador::Interpretador() {

}

vector<FiguraGeometrica*> Interpretador::analise(string filename) {

    vector<FiguraGeometrica*> figs;
    ifstream fin; //objeto para leitura do arquivo
    stringstream ss; //stringstream
    string s;
    string token;

    fin.open(filename.c_str()); //abertura de fluxo com arquivo recebido no parâmetro
    if(!fin.is_open()) {

        cout << "Arquivo não foi aberto!";
        exit(0);
    }

    while (fin.good()) {

        getline(fin, s); //utiliza fin como entrada e grava em s

        if(fin.good()) {

            ss.clear(); //limpa o estado do fluxo
            ss.str(s); //atribui o string "s" ao fluxo depois da limpeza
            ss >> token;

            if(ss.good()) {

                if(token.compare("Dim")==0) {

                    ss >> dimx >> dimy >> dimz;
                }

                else if(token.compare("PutVoxel")==0) {

                    int x;
                    int y;
                    int z;

                    ss >> x >> y >> z >> r >> g >> b >> a; //conecta uma string do arquivo a uma variável em memória

                    figs.push_back(new PutVoxel(x, y, z, r, g, b, a)); //putvoxel vira um elemento do vetor figs
                }

                else if(token.compare("CutVoxel")==0) {

                    int x;
                    int y;
                    int z;

                    ss >> x >> y >> z;

                    figs.push_back(new CutVoxel(x, y, z));
                }

                else if(token.compare("PutBox")==0) {

                    int x0;
                    int x1;
                    int y0;
                    int y1;
                    int z0;
                    int z1;

                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;

                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }

                else if(token.compare("CutBox")==0) {

                    int x0;
                    int x1;
                    int y0;
                    int y1;
                    int z0;
                    int z1;

                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }

                else if(token.compare("PutSphere")==0) {

                    int xc;
                    int yc;
                    int zc;
                    int raio;

                    ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;

                    figs.push_back(new PutSphere(xc, yc, zc, raio, r, g, b, a));
                }

                else if(token.compare("CutSphere")==0) {

                    int xc;
                    int yc;
                    int zc;
                    int raio;

                    ss >> xc >> yc >> zc >> raio;

                    figs.push_back(new CutSphere(xc, yc, zc, raio));
                }

                //putplanet
                else if(token.compare("PutPlanet")==0) {

                    int xc;
                    int yc;
                    int zc;
                    int raio;
                    std::string caminhoimg;

                    ss >> xc >> yc >> zc >> raio >> caminhoimg;

                    figs.push_back(new PutPlanet(xc, yc, zc, raio, caminhoimg));
                }
                else if(token.compare("PutEllipsoid")==0) {

                    int xc;
                    int yc;
                    int zc;
                    int raiox;
                    int raioy;
                    int raioz;

                    ss >> xc >> yc >> zc >> raiox >> raioy >> raioz >> r >> g >> b >> a;

                    figs.push_back(new PutEllipsoid(xc, yc, zc, raiox, raioy, raioz, r, g, b, a));
                }

                else if(token.compare("CutEllipsoid")==0) {

                    int xc;
                    int yc;
                    int zc;
                    int raiox;
                    int raioy;
                    int raioz;

                    ss >> xc >> yc >> zc >> raiox >> raioy >> raioz;

                    figs.push_back(new CutEllipsoid(xc, yc, zc, raiox, raioy, raioz));
                }
            }
        }
    }

    return (figs);
}

int Interpretador::getDimx() {

    return dimx;
}

int Interpretador::getDimy() {

    return dimy;
}

int Interpretador::getDimz() {

    return dimz;
}
