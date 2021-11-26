#include <iostream>
#include "betun.h"

using namespace std;

Betun::Betun() {
    this->material = nullptr;
    this->costo = 0;
}

Betun::Betun(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x , pos_y){
    this->material = nullptr;
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
    delete this->material;
}

void Betun::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_BLACK_232  << "  " << END_COLOR;
    else
        cout << this->material->devolver_emoji() << END_COLOR;
}

void Betun::agregar_material(Material* material) {
    this->material = material;
    modificar_ocupado(true);
}

Material* Betun::devolver_material() {
    return this->material;
}

void Betun::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        this->material->imprimir_resumen();
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}
