#include <iostream>
#include "camino.h"

using namespace std;

Camino::Camino() {
    this->material = nullptr;
    this->costo = 0;
}

Camino::Camino(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x, pos_y){
    this->material = nullptr;
    this->costo = 0;
}

void Camino::modificar_terreno(string elemento,int accion){
    //crear material y asignarlo a Materiales
}

void Camino::modicar_costo(int costo) {
    this->costo = costo;
}

int Camino::devolver_costo() {
    return this->costo;
}

Camino::~Camino() {
    delete this->material;
}

void Camino::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_GRAY_243 << "  " << END_COLOR;
    else
        cout << BGND_GRAY_243  << this->material->devolver_emoji()  << END_COLOR;
}

void Camino::agregar_material(Material* material) {
    this->material = material;
    modificar_ocupado(true);
}

Material* Camino::devolver_material() {
    return this->material;
}

void Camino::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        this->material->imprimir_resumen();
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}

