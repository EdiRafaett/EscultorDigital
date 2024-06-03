#include "sculptor.h" //inclusão de declaração da classe
#include <iostream> //inclusão das funções de entrada e saída
#include <cmath> //inclusão de funções matemáticas
#include <fstream> //inclusão de fluxo para arquivos
#include <cstdlib> //inclusão de função exit

#include <queue>
#include <iomanip>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) { //parametro da função

    //Passagem dos valores dos parametros para as variáveis privadas:
    nx = _nx;
    ny = _ny;
    nz = _nz;

    // Atribuindo zero as  variáveis de cores e transparência:
    r = 0;
    g = 0;
    b = 0;
    a = 0;

    //Declarando incrementadores dos laços:
    int i, j, k;

    //ALOCANDO MEMÓRIA PARA MATRIZ 3D:
    //Alocando memória para o array auxiliar que receberá endereços das linhas onde inicia-se cada plano:
    v = new Voxel **[nx];
    //Alocando memória para o array que receberá o endereço do voxel de inicio de cada linha:
    v[0] = new Voxel *[nx * ny];
    //Alocando memória  para todos os voxels da matriz:
    v[0][0] = new Voxel [nx * ny * nz];
    //Passando os endereços de inicio de cada plano para o array auxiliar:
    for (i = 1; i < nx; i++){
        v[i] = v[i - 1] + ny;
    }
    //Passando os endereços dos voxels de início de cada linha de cada plano:
    for(i = 0; i < nx; i++){
        if(i != 0){
            v[i][0] = v[i - 1][ny - 1] + nz;
        }
        for (j = 1; j < ny; j++){
            v[i][j] = v[i][j - 1] + nz;
        }
    }

    //Iniciando os voxels com cores e transparência zero e estado false:
    for(i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                this -> v[i][j][k].r = this -> r;
                this -> v[i][j][k].g = this -> g;
                this -> v[i][j][k].b = this -> b;
                this -> v[i][j][k].a = this -> a;
                this -> v[i][j][k].isOn = false;
            }
        }
    }
}

/*=================================================================================
IMPLEMENTO DO DESTRUIDOR DE CLASSES:
=================================================================================*/
Sculptor::~Sculptor(){
    //Liberação da memória:
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}
//implementação do membro de seleção de cor de voxel
void Sculptor::setColor(float r, float g, float b, float alpha) {

    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha;
    //atribui cores e transparência de acordo com os parâmetros
}

//implementação do membro de ativação de voxel
void Sculptor::putVoxel(int x, int y, int z) {

    if ((this -> nx > x) && (x >= 0) && (this -> ny > y) && (y >= 0) && (this -> nz > z) && (z >= 0)) {

        this -> v[x][y][z].isOn = true;

        this -> v[x][y][z].r = this -> r;
        this -> v[x][y][z].g = this -> g;
        this -> v[x][y][z].b = this -> b;
        this -> v[x][y][z].a = this -> a;
        //ativa o voxel e atribui a ele a cor atual se a posição for válida
    }
}

//implementação do membro de desativação de voxel
void Sculptor::cutVoxel(int x, int y, int z) {
    if ((this -> nx > x) && (x >= 0) && (this -> ny > y) && (y >= 0) && (this -> nz > z) && (z >= 0)) {
        this -> v[x][y][z].isOn = false;
        //desativa o voxel se a posição for válida
    }
}

//implementação do membro de gravação de arquivo
void Sculptor::writeOFF(char *filename) {

    int i;
    int j;
    int k;
    int n_voxels;
    //contadores de iteração

    int n_vertices; //contador de vertices

    n_voxels = 0;

    ofstream fout; //objeto para fluxo de saída

    fout.open (filename); //abertura de fluxo para arquivo

    if(!fout.is_open()) {

        cout << "O arquivo não pôde ser aberto" << endl;

        exit (1);
    } //verifica abertura do fluxo

    for (i = 0; i < nx; i++) {

        for (j = 0; j < ny; j++) {

            for (k = 0; k < nz; k++) {

                if (v[i][j][k].isOn == true) {

                    n_voxels = n_voxels + 1; //guarda o número de voxels ativados atualmente
                }
            }
        }
    }

    fout << "OFF" << endl; //escreve no arquivo o tipo de arquivo
    fout << n_voxels*8 << " " << n_voxels*6 << " " << n_voxels*0 << endl; //escreve no arquivo o número de vértices, faces e arestas


    for (i = 0; i < nx; i++) {

        for (j = 0; j < ny; j++) {

            for (k = 0; k < nz; k++) {

                if (v[i][j][k].isOn == true) {

                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl; //PO
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl; //P1
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl; //P2
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl; //P3
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl; //P4
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl; //P5
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl; //P6
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl; //P7
                }
            }
        }
    } //define as coordenadas dos vértices do cubo

    n_voxels = 0; //torna a variável para o valor nulo

    for (i = 0; i < nx; i++) {

        for (j = 0; j < ny; j++) {

            for (k = 0; k < nz; k++) {

                if (v[i][j][k].isOn == true) {

                    n_vertices = n_voxels * 8;
                    fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 1 << " " << n_vertices + 2 << " " << n_vertices + 3 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 3 << " " << n_vertices + 5 << " " << n_vertices + 4 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    fout << "4" << " " << n_vertices + 4 << " " << n_vertices + 5 << " " << n_vertices + 7 << " " << n_vertices + 6 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    fout << "4" << " " << n_vertices + 1 << " " << n_vertices + 6 << " " << n_vertices + 7 << " " << n_vertices + 2 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 4 << " " << n_vertices + 6 << " " << n_vertices + 1 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    fout << "4" << " " << n_vertices + 2 << " " << n_vertices + 7 << " " << n_vertices + 5 << " " << n_vertices + 3 << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << endl;
                    n_voxels = n_voxels + 1;
                }
            }
        }
    } //define número de vértices, referência dos vértices, cor e transparência de cada face do voxel

    fout.close(); //fecha o fluxo
}
