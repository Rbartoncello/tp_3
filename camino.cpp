#include <iostream>
#include "camino.h"

using namespace std;

Camino::Camino() {
    this->material = nullptr;
    this->costo = 4;
}

Camino::Camino(char tipo_terreno, int pos_x, int pos_y) : Casillero_transitable(tipo_terreno, pos_x, pos_y){
    this->material = nullptr;
    this->costo = 4;
}

void Camino::modificar_terreno(string elemento,int accion){
    //crear material y asignarlo a Materiales
}

void Camino::modificar_costo(int costo) {
    this->costo = costo;
}

int Camino::devolver_duenio() {}

int Camino::devolver_costo() {
    return this->costo;
}

Camino::~Camino() {
    delete this->material;
}

void Camino::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_GRAY_243  << "  " << END_COLOR;
    else if (material != nullptr)
        cout << BGND_GRAY_243  << this->material->devolver_emoji() << END_COLOR;
    else
        cout << BGND_GRAY_243  << devolver_jugador()->devolver_emoji() << END_COLOR;
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
        if (material != nullptr)
            this->material->imprimir_resumen();
        else
            cout <<"\tSoy el jugador: " << devolver_jugador()->devolver_numero() << " ( " << devolver_jugador()->devolver_emoji() << " ) y me encuentro en el casillero consultado."<< endl;
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}

void Camino::agregar_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}

void Camino::eliminar_jugador() {
    modificar_jugador(nullptr);
    modificar_ocupado(false);
}

void Camino::mover_jugador(Jugador* jugador) {
    if (esta_ocupado() && material != nullptr){
        jugador->aumentar_material(material);
        delete material;
        material = nullptr;
    }
    
    modificar_jugador(jugador);
    modificar_ocupado(true);
}