#include "casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_construible::Casillero_construible(): Casillero(){

}

bool Casillero_construible::esta_ocupado(){
    return this->ocupado;
}

void Casillero_construible::modificar_ocupado(bool estado) {
    this->ocupado = estado;
}

Material* Casillero_construible::devolver_material(){return nullptr;}

Casillero_construible::~Casillero_construible(){}