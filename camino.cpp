#include <iostream>
#include "camino.h"

using namespace std;


Camino::Camino() {
    this->costo = 0;
}

Camino::Camino(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x, pos_y){
    this->costo = 0;
}

void Camino::modicar_costo(int costo) {
    this->costo = costo;
}

int Camino::devolver_costo() {
    return this->costo;
}

Camino::~Camino() {

}

void Camino::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_GRAY_243 << "  " << END_COLOR;
}

