#include <iostream>
#include "betun.h"

using namespace std;

Betun::Betun() {
    this->costo = 0;
}

Betun::Betun(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x , pos_y){
    this->costo = 0;
}

void Betun::modificar_terreno(string elemento,int accion){
    //crear material y asignarlo a Materiales
}

void Betun::modicar_costo(int costo) {
    this->costo = costo;
}

int Betun::devolver_costo() {
    return this->costo;
}

Betun::~Betun() {

}

void Betun::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_BLACK_232  << "  " << END_COLOR;
}
