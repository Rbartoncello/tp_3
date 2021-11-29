#include <iostream>
#include "muelle.h"

using namespace std;


Muelle::Muelle() {
    this->material = nullptr;
    this->costo = 5;
}

Muelle::Muelle(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x, pos_y){
    this->material = nullptr;
    this->costo = 5;
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
    delete this->material;
}

void Muelle::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_BROWN_94 << "  " << END_COLOR;
    else
        cout << BGND_BROWN_94  << this->material->devolver_emoji() << END_COLOR;
}

void Muelle::agregar_material(Material* material) {
    this->material = material;
    modificar_ocupado(true);
}

Material* Muelle::devolver_material() {
    return this->material;
}

void Muelle::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        this->material->imprimir_resumen();
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}



