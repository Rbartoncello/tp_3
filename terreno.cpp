#include <iostream>
#include "terreno.h"

using namespace std;

Terreno::Terreno() {
    this->costo = 0;
}

Terreno::Terreno(char tipo_terreno, int pos_x, int pos_y) : Casillero_construible(tipo_terreno, pos_x, pos_y) {
    this->costo = 0;
}

void Terreno::modicar_costo(int costo) {
    this->costo = costo;
}

int Terreno::devolver_costo() {
    return this->costo;
}

Terreno::~Terreno() {

}

void Terreno::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
}
