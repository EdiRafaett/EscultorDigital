#include "sculptor.h" //inclusão de declaração da classe
#include <iostream> //inclusão das funções de entrada e saída
#include <cmath> //inclusão de funções matemáticas
#include <fstream> //inclusão de fluxo para arquivos
#include <cstdlib> //inclusão de função exit
#include <queue>
#include <iomanip>

using namespace std;

/*=====Implementação da classe Sculptor:=====*/
Sculptor::Sculptor(int _nx, int _ny, int _nz) { //parametro da função

//Passagem dos valores dos parametros para as variáveis privadas:
    nx = _nx;
    ny = _ny;
    nz = _nz;

// Atribuindo zero as  variáveis de cores e transparência:
    r = 0, g = 0, b = 0, a = 0;

    //ALOCANDO MEMÓRIA PARA MATRIZ 3D:
    //Alocando memória para o array auxiliar que receberá endereços das linhas onde inicia-se cada plano:
    v = new Voxel **[nx];
    //Alocando memória para o array que receberá o endereço do voxel de inicio de cada linha:
    v[0] = new Voxel *[nx * ny];
    //Alocando memória  para todos os voxels da matriz:
    v[0][0] = new Voxel [nx * ny * nz];
    //Passando os endereços de inicio de cada plano para o array auxiliar:
    for (int i = 1; i < nx; i++){
        v[i] = v[i - 1] + ny;
    }
    //Passando os endereços dos voxels de início de cada linha de cada plano:
    for(int i = 1; i < nx*ny; i++){
        v[0][i] = v[0][i-1]+nz;

    }

    //Iniciando os voxels com cores e transparência zero e estado false:
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                this -> v[i][j][k].r = this -> r;
                this -> v[i][j][k].g = this -> g;
                this -> v[i][j][k].b = this -> b;
                this -> v[i][j][k].a = this -> a;
                this -> v[i][j][k].isOn = false;
            }
        }
    }
}

//Implementando o destuidor da classe
Sculptor::~Sculptor(){
    //Liberação da memória:
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

//Implementando o método setColor
void Sculptor::setColor(float r, float g, float b, float alpha) {

//atribuindo cores e transparência de acordo com os parâmetros
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha;
}

//Implementando o método putVoxel
void Sculptor::putVoxel(int x, int y, int z) {

//Verifica se as coordenadas são válidas
    if ((this -> nx > x) && (x >= 0) && (this -> ny > y) && (y >= 0) && (this -> nz > z) && (z >= 0)) {
//Se posição válida, ativa o voxel e passa os parametros
        this -> v[x][y][z].isOn = true;
        this -> v[x][y][z].r = this -> r;
        this -> v[x][y][z].g = this -> g;
        this -> v[x][y][z].b = this -> b;
        this -> v[x][y][z].a = this -> a;
    }
}

//Implementação do método curVoxel
void Sculptor::cutVoxel(int x, int y, int z) {
    //verifica se a posição é válida
    if ((this -> nx > x) && (x >= 0) && (this -> ny > y) && (y >= 0) && (this -> nz > z) && (z >= 0)) {
        //desativa o voxel se a posição for válida
        this -> v[x][y][z].isOn = false;
    }
}

//Implementação do método de gravação em arquivo
void Sculptor::writeOFF(char *filename) {

    int n_voxels = 0, n_vertices; //contador voxels e vertices

    ofstream fout; //objeto para fluxo de saída
    fout.open (filename); //abertura de fluxo para arquivo

    if(!fout.is_open()) {
        cout << "O arquivo não pôde ser aberto" << endl;
        exit (1);
    } //verifica abertura do fluxo

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].isOn == true) { //verifica se voxel está ativo
                    n_voxels = n_voxels + 1; //guarda o número de voxels ativados atualmente
                }
            }
        }
    }

    fout << "OFF" << endl; //especificador de arquivo obrigatório em arquivos OFF
    fout << n_voxels*8 << " " << n_voxels*6 << " " << n_voxels*0 << endl; //escreve no arquivo o número de vértices, faces e arestas

    for (int i = 0; i < nx; i++) {

        for (int j = 0; j < ny; j++) {

            for (int k = 0; k < nz; k++) {
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

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
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
