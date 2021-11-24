#include <iostream>
#include "muelle.h"

using namespace std;


Muelle::Muelle() {
    this->costo = 0;
}

Muelle::Muelle(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x, pos_y){
    this->costo = 0;
}

void Muelle::modificar_terreno(string elemento,int accion){
    //crear material y asignarlo a Materiales
}

void Muelle::modicar_costo(int costo) {
    this->costo = costo;
}

int Muelle::devolver_costo() {
    return this->costo;
}

Muelle::~Muelle() {

}

void Muelle::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_BROWN_94 << "  " << END_COLOR;
}

