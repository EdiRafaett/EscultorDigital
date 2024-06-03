#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {

    this -> x = x;
    this -> y = y;
    this -> z = z;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutVoxel::~PutVoxel() {

}

void PutVoxel::draw(Sculptor &s) {

    s.setColor(r, g, b, a);
    s.putVoxel(x, y, z);
} //draw irá passar como argumento o que foi atribuído pelo construtor, nos atributos da classe herdeira, para
