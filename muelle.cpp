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

int Muelle::devolver_duenio() {return 0;}


void Muelle::modificar_terreno(string elemento,int accion){
    //crear material y asignarlo a Materiales
}

void Muelle::modificar_costo(int costo) {
    this->costo = costo;
}

int Muelle::devolver_costo() {
    return this->costo;
}

Muelle::~Muelle() {
    delete this->material;
}

void Muelle::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_BROWN_94  << "  " << END_COLOR;
    else if (material != nullptr)
        cout << BGND_BROWN_94  << this->material->devolver_emoji() << END_COLOR;
    else
        cout << BGND_BROWN_94  << devolver_jugador()->devolver_emoji() << END_COLOR;
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
        if (material != nullptr)
            this->material->imprimir_resumen();
        else
            cout <<"\tSoy el jugador: " << devolver_jugador()->devolver_numero() << " ( " << devolver_jugador()->devolver_emoji() << " ) y me encuentro en el casillero consultado."<< endl;
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}

void Muelle::agregar_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}

void Muelle::eliminar_jugador() {
    modificar_jugador(nullptr);
    modificar_ocupado(false);
}

void Muelle::mover_jugador(Jugador* jugador) {
    if (esta_ocupado()){
        jugador->aumentar_material(material);
        delete material;
        material = nullptr;
    }
    
    modificar_jugador(jugador);
    modificar_ocupado(true);
}
