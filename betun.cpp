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

void Betun::modificar_costo(int costo) {
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
    else if (material != nullptr)
        cout << this->material->devolver_emoji() << END_COLOR;
    else
        cout << devolver_jugador()->devolver_emoji() << END_COLOR;
}

void Betun::agregar_material(Material* material_nuevo) {
    this->material = material_nuevo;
    modificar_ocupado(true);
}

Material* Betun::devolver_material() {
    return this->material;
}

void Betun::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        if (material != nullptr)
            this->material->imprimir_resumen();
        else
            cout <<"\tSoy el jugador: " << devolver_jugador()->devolver_numero() << " ( " << devolver_jugador()->devolver_emoji() << " ) y me encuentro en el casillero consultado."<< endl;
    } else
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
}

void Betun::agregar_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}

void Betun::eliminar_jugador() {
    modificar_jugador(nullptr);
    modificar_ocupado(false);
}

void Betun::mover_jugador(Jugador* jugador) {
    if (esta_ocupado() && material != nullptr){
        jugador->aumentar_material(material);
        if ( material->devolver_nombre() == ANDYCOINS )
            jugador->sumar_a_objetivo(material->devolver_cantidad(),COMPRAR_ANDYPOLIS);
        delete material;
        material = nullptr;
    }
    
    modificar_jugador(jugador);
    modificar_ocupado(true);
}
