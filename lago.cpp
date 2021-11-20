#include <iostream>
#include "lago.h"

using namespace std;

Lago::Lago() {
    this->costo = 0;
}

Lago::Lago(char tipo_terreno, int pos_x, int pos_y) : Casillero_inaccesible(tipo_terreno, pos_x, pos_y) {
    this->costo = 0;
}

void Lago::modicar_costo(int costo) {
    this->costo = costo;
}

int Lago::devolver_costo() {
    return this->costo;
}

Lago::~Lago() {

}

void Lago::mostrar(){
    cout << BGND_LIGHT_BLUE_68 << "  " << END_COLOR;
}
